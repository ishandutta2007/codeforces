#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second
#define EPS 0.0000000000000001
using namespace std;

set<set<vector<int> > > s;

int upd(int a, int b, int c, int d)
{
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    set<vector<int> > s2;
    vector<int> a0;
    for (int i=1; i<=4; i++)
    {
        int t=d;
        d=c;
        c=b;
        b=a;
        a=t;
        a0.push_back(a);
        a0.push_back(b);
        a0.push_back(c);
        a0.push_back(d);
        s2.insert(a0);
        a0.clear();
    }
    s.insert(s2);
}

main()
{
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    upd(s1[0]-'0', s1[1]-'0', s2[1]-'0', s2[0]-'0');
    for (int i=2; i<=n; i++)
    {
        cin>>s1>>s1>>s2;
        upd(s1[0]-'0', s1[1]-'0', s2[1]-'0', s2[0]-'0');
    }
    cout<<s.size()<<"\n";
}