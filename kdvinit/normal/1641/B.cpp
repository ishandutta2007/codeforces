/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<pair<int, int>> oper;
vector<int> len;
int base;

void calc(vector<int> a)
{
    vector<int> b;
    int n = a.size();
    if(n==0)return;

    int j=1;
    while(a[j]!=a[0]) j++;

    if(j==1)
    {
        len.push_back(2);
        base+=2;
        for(int i=2; i<n; i++) b.push_back(a[i]);
        calc(b);
        return;
    }

    for(int i=1; i<j; i++)
    {
        b.push_back(a[i]);

        int y = base+j+i;
        oper.push_back({y, a[i]});
    }

    int m = b.size();
    reverse(b.begin(), b.end());

    for(int i=j+1; i<n; i++) b.push_back(a[i]);

    int z = 2*(m+1);
    len.push_back(z);
    base+=z;
    calc(b);
}

void solve()
{
    int n;
    cin>>n;

    vector<int> a;
    map<int, int> mp;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mp[x]++;
        a.push_back(x);
    }

    for(int x: a)
    {
        if(mp[x]%2==1) { cout<<-1<<endl; return; }
    }

    oper.clear(); len.clear();

    base=0;
    calc(a);

    cout<<oper.size()<<endl;
    for(pair<int, int> x: oper) cout<<x.first<<" "<<x.second<<endl;

    cout<<len.size()<<endl;
    for(int x: len) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}