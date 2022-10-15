/*
K.D. Vinit  /,,/
Dont stalk my code : )
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    string s;
    cin>>s;

    int sl = s.size();
    int dl=0, dr=0, du=0, dd=0;
    int ml=0, mr=0, mu=0, md=0;

    for(int i=0; i<sl; i++)
    {
        char x = s[i];

        if(x=='L')
        {
            dl++;
            dr--;
            if(dl+mr==m) break;
            ml = max(ml, dl);
        }
        if(x=='R')
        {
            dr++;
            dl--;
            if(dr+ml==m) break;
            mr = max(mr, dr);
        }
        if(x=='D')
        {
            dd++;
            du--;
            if(dd+mu==n) break;
            md = max(md, dd);
        }
        if(x=='U')
        {
            du++;
            dd--;
            if(du+md==n) break;
            mu = max(mu, du);
        }
    }

    cout<<mu+1<<" "<<ml+1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}