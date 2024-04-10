#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
void solve()
{
    int a;
    long long b;
    cin>>a>>b;
    long long c = b/2;
    if(b%2)
        c++;
    long long sum=0;
    bool czy=false;
    int ind = -1;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        if(tab[x]>=c && tab[x]<=b)
        {
            czy=true;
            ind = x;
        }
        if(tab[x]<=b)
            sum+=tab[x];
    }
    if(czy)
    {
        cout<<1<<'\n'<<ind<<'\n';
        return;
    }
    if(sum>=c)
    {
        vector<int> v;
        sum=0;
        for(int x=1;x<=a;x++)
        {
            if(sum>=c && sum<=b)
                break;
            if(tab[x]<=b)
            {
                sum+=tab[x];
                v.push_back(x);
            }
        }
        cout<<v.size()<<'\n';
        for(auto x:v)
            cout<<x<<" ";
        cout<<'\n';
    }
    else
        cout<<-1<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}