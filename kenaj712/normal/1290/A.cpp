#include<bits/stdc++.h>
using namespace std;
int tab[3505];
vector<int> v;
multiset<int> s;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    c=min(c,b-1);
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int co_ile=a-b;
    for(int x=0;x+co_ile<a;x++)
        v.push_back(max(tab[x],tab[x+co_ile]));
    int mini=0;
    for(int x=0;x<v.size()-c;x++)
        s.insert(v[x]);
    mini=*s.begin();
    for(int x=v.size()-c;x<v.size();x++)
    {
        s.erase(s.lower_bound(v[x-(v.size()-c)]));
        s.insert(v[x]);
        mini=max(mini,*s.begin());
    }
    cout<<mini<<'\n';
    v.resize(0);
    s.clear();
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