#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int y;
    cin>>y;
    string a;
    cin>>a;
    string d = a;
    sort(d.begin(),d.end());
    int licz = a.size();
    for(int x=0;x<a.size();x++)
        if(d[x] == a[x])
            licz--;
    cout<<licz<<'\n';
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