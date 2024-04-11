#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=1000500;
typedef long long ll;
#define int ll

int n;
int v[nmax];

int old(int x)
{
    int c=-1;
    while (x>0)
        x/=2, c++;
    return c;
}

int ans(int l, int r, int mask)
{
//    cout<<l<<" "<<r<<" "<<mask<<"\n";

    if (l==r)
        return 1;

    vector<int> ch;
    int cur = old(v[l]^mask);
    for (int i=l+1; i<=r; i++)
    {
        int nt=old(v[i]^mask);
        if (nt!=cur)
        {
            ch.pb(i);
            cur=nt;
        }
    }
    if (ch.size() == 0)
        return ans(l, r, mask^(1ll<<old(v[l]^mask)));
    else
    {
        ch.pb(r+1);
//        for (int i:ch)
//            cout<<i<<" ";
//        cout<<"\n";
        int pos = ans(l, ch[0]-1, mask^(1ll<<old(v[l]^mask)) );

//        int pos1 = ans(l, ch[0]-1, mask^(1ll<<old(v[l]^mask)) );
//        int pos2 = ans(ch[0], ch[1]-1, mask^(1ll<<old(v[ch[0]]^mask)) );
//        return max(pos1, pos2) + ch.size() - 1;

        int answ = pos + ch.size() - 1;
        for (int i=0; i+1<ch.size(); i++)
        {
            int posx=ans(ch[i], ch[i+1]-1, mask^(1ll<<old(v[ch[i]]^mask)));
            answ=max(answ, posx + (int(ch.size())-i) - 1);
        }
        return answ;

    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i], v[i]=2*v[i]+1;
    sort(v+1, v+n+1);
    cout<<n-ans(1, n, 0)<<"\n";
}