#include<bits/stdc++.h>
using namespace std;
int tab[1005];
void solve()
{
    int a;
    cin>>a;
    int sum=0;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        sum+=tab[x];
    }
    if(sum==0)
        cout<<"NO"<<'\n';
    else
    {
        cout<<"YES"<<'\n';
        sort(tab,tab+a);
        if(sum>0)
            reverse(tab,tab+a);
        for(int x=0;x<a;x++)
            cout<<tab[x]<<" ";
        cout<<'\n';
    }
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