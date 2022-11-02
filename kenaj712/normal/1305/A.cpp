#include<bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> v2;
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        v1.push_back(b);
    }
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(auto x:v1)
        cout<<x<<" ";
    cout<<'\n';
    for(auto x:v2)
        cout<<x<<" ";
    cout<<'\n';
    v1.resize(0);
    v2.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}