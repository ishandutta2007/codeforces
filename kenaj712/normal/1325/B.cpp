#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a;
    cin>>a;
    int b;
    set<int> s;
    while(a--)
    {
        cin>>b;
        s.insert(b);
    }
    cout<<s.size()<<'\n';
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