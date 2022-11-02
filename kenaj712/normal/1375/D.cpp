#include<bits/stdc++.h>
using namespace std;
int tab[1005];
bool odw[1005];
vector<int> v;
int mex(int a)
{
    for(int x=0;x<a;x++)
        odw[tab[x]]=true;
    int pom;
    for(int x=0;x<=a;x++)
        if(!odw[x])
        {
            pom=x;
            break;
        }
    for(int x=0;x<=a;x++)
        odw[x]=false;
    return pom;
}
bool sorted(int a)
{
    for(int x=0;x<a-1;x++)
        if(tab[x]>tab[x+1])
            return false;
    return true;
}
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    while(!sorted(a))
    {
        int pom=mex(a);
        if(pom==a)
        {
            for(int x=0;x<a;x++)
                if(tab[x]!=x)
                {
                    v.push_back(x+1);
                    tab[x]=pom;
                    break;
                }
        }
        else
        {
            v.push_back(pom+1);
            tab[pom]=pom;
        }
    }
    cout<<v.size()<<'\n';
    for(auto x:v)
        cout<<x<<" ";
    cout<<'\n';
    v.resize(0);
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