#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long

using namespace std;

int n;
string s;
int a[200500];
int cnt[200500][26];

int sum(int l, int r, int k)
{
    return cnt[r][k]-cnt[l-1][k];
}

bool ans(int l, int r)
{
    if (l==r)
        return true;
    if (a[l]!=a[r])
        return true;
    if (sum(l, r, a[l])>=r-l)
        return false;
    int c=0;
    for (int i=0; i<26; i++)
        if (sum(l, r, i)>0)
            c++;
    if (c>=3)
        return true;
    else
        return false;
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cin>>s;
    n=s.size();
    for (int i=1; i<=n; i++)
    {
        a[i]=int(s[i-1]-'a');
        for (int j=0; j<26; j++)
            cnt[i][j]=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int l, r;
        cin>>l>>r;
        if (ans(l, r))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}