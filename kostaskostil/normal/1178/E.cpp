#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;

int p[1005000];
vector<pair<int, int> > g;
int n;
int a[100500];
int cnt=0;

void added(int v1, int v2)
{
    g.pb({v1, v2});
    a[v1]++;
    a[v2]++;
    cnt++;
}

void out()
{
    cout<<cnt<<"\n";
    for (auto pa:g)
        cout<<pa.fi<<" "<<pa.se<<"\n";
    exit(0);
}
main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

    string s;
    cin>>s;
    int c=0;
    int n=s.size();
    string ans="";
    for (int i=1; i<=n/4; i++)
    {
        int r=n-2-c;

        if (s[c]==s[r])
            ans+=s[c];
        else
        if (s[c]==s[r+1])
            ans+=s[c];
        else
        if (s[c+1]==s[r])
            ans+=s[c+1];
        else
        if (s[c+1]==s[r+1])
            ans+=s[c+1];
        c+=2;
    }

    cout<<ans;
    if (n%4!=0)
        cout<<s[c];
    if (ans.size()>0)
    for (int i=ans.size()-1; i>=0; i--)
        cout<<ans[i];
    return 0;
}