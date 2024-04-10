#include<bits/stdc++.h>
using namespace std;
int tab[200005];
vector<int> v;
int pref[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    while(a--)
    {
        cin>>b;
        tab[b]++;
    }
    for(int x=1;x<=2e5;x++)
        pref[x]=pref[x-1]+tab[x];
    for(int x=1;x<=2e5;x++)
        if(tab[x]==1||(tab[x-1]==0&&tab[x]!=0)||(tab[x+1]==0&&tab[x]!=0))
            v.push_back(x);
    pair<int,pair<int,int>> p=make_pair(-1,make_pair(-1,-1));
    for(auto x:v)
        p=max(p,make_pair(tab[x],make_pair(x,x)));
    for(int x=0;x<v.size()-1;x++)
        if(tab[v[x]+1]>0)
            p=max(p,make_pair(pref[v[x+1]]-pref[v[x]-1],make_pair(v[x],v[x+1])));
    cout<<p.first<<'\n';
    for(int x=p.second.second;x>=p.second.first;x--)
        cout<<x<<" ";
    for(int x=p.second.first;x<=p.second.second;x++)
    {
        tab[x]--;
        while(tab[x]--)
            cout<<x<<" ";
    }
	return 0;
}