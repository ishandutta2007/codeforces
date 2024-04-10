#include<bits/stdc++.h>
using namespace std;
bool ok[1000005];
int tab[1000005];
bool ok2[1000005];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        ok[tab[x]]=true;
    }
    for(int x=0;x<2*a;x++)
    {
        if(x%2==0)
            v.push_back(tab[0]);
        else
            v.push_back(tab[x/2]);
    }
    for(int x=0;x<2*a;x++)
    {
        int pom=v[x];
        for(int y=x;y<2*a;y++)
        {
            pom=__gcd(pom,v[y]);
            ok2[pom]=true;
        }

    }
    for(int x=0;x<=1e6;x++)
        if(ok[x]==false&&ok2[x]==true)
        {
            cout<<-1;
            return 0;
        }
    cout<<2*a<<'\n';
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}