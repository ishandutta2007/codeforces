#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<int> v;
multiset<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int suma=0;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        v.push_back(-tab[x]);
    }
    sort(v.begin(),v.end());
    for(int x=0;x<b;x++)
    {
        suma-=v[x];
        s.insert(-v[x]);
    }
    cout<<suma<<'\n';
    int ile=1;
    for(int x=0;x<a;x++)
    {
        if(s.find(tab[x])!=s.end()&&s.size()>1)
        {
            s.erase(s.lower_bound(tab[x]));
            cout<<ile<<" ";
            ile=1;
        }
        else
            ile++;
    }
    cout<<ile-1;
	return 0;
}