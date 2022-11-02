#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int gdzie[1000005];
vector<pair<int,int>> v;
void zamien(int a,int b)
{
    if(a==b)
        return;
    v.push_back(make_pair(a,b));
    swap(tab[a],tab[b]);
    swap(gdzie[tab[a]],gdzie[tab[b]]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        gdzie[tab[x]]=x;
    }
    for(int x=1;x<=a/2;x++)
    {
        if(gdzie[x]==x)
            continue;
        if(gdzie[x]<=a/2)
        {
            zamien(gdzie[x],a);
            zamien(x,a);
        }
        else
        {
            int pom=gdzie[x];
            zamien(gdzie[x],1);
            zamien(1,a);
            zamien(a,x);
            zamien(1,pom);
        }
    }
    for(int x=a/2+1;x<=a;x++)
    {
        if(gdzie[x]==x)
            continue;
        int pom=gdzie[x];
        zamien(gdzie[x],1);
        zamien(1,x);
        zamien(1,pom);
    }
    cout<<v.size()<<'\n';
    for(auto x:v)
        cout<<x.first<<" "<<x.second<<'\n';

	return 0;
}