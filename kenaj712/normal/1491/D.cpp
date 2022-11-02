#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;
    if(__builtin_popcount(b) > __builtin_popcount(a))
    {
        cout<<"NO\n";
        return;
    }
    int pom = __builtin_popcount(a) - __builtin_popcount(b);
    vector<int> v1;
    vector<int> v2;
    for(int x=0;x<=29;x++)
    {
        if(a&(1<<x))
            v1.push_back(x);
        if(b&(1<<x))
            v2.push_back(x);
    }
    while(!v2.empty())
    {
        if(v1.back() > v2.back())
        {
            cout<<"NO\n";
            return;
        }
        if(v1.back() == v2.back())
        {
            v1.pop_back();
            v2.pop_back();
            continue;
        }
        v1.pop_back();
        v2.pop_back();
        while(v1.size()!=v2.size())
            v1.pop_back();
        break;
    }
    if(v1.size() != v2.size())
    {
            cout<<"NO\n";
            return;
    }

    while(!v1.empty())
    {
        if(v1.back() > v2.back())
        {
            cout<<"NO\n";
            return;
        }
        v1.pop_back();
        v2.pop_back();
    }
    cout<<"YES\n";
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