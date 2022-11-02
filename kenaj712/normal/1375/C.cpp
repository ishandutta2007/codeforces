#include<bits/stdc++.h>
using namespace std;
set<int> s;
set<int> s2;
int tab[1000005];
void solve()
{
    int a;
    cin>>a;
    s.insert(a+1);
    s2.insert(0);
    bool czy=true;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        s2.insert(tab[x]);
    }
    for(int x=0;x<a;x++)
    {
        s2.erase(tab[x]);
        if(*s.begin()>tab[x] && *s2.rbegin()<tab[x])
            czy=false;
        s.insert(tab[x]);
    }
    if(tab[0]<tab[a-1])
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
    s.clear();
    s2.clear();
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