#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<int> v;
bool ok[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=0;x<a;x++)
        cin>>ok[x];
    for(int x=0;x<a;x++)
        if(!ok[x])
            v.push_back(tab[x]);
    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
    for(int x=0;x<a;x++)
    {
        if(ok[x])
            cout<<tab[x];
        else
        {
            cout<<v.back();
            v.pop_back();
        }
        cout<<" ";
    }
    cout<<'\n';
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