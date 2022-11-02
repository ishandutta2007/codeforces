#include<bits/stdc++.h>
using namespace std;
int tab[3000005];
int b;
vector<int> v;
int check(int a)
{
    if(tab[2*a]==0 && tab[2*a+1]==0)
        return a;
    if(tab[2*a]>tab[2*a+1])
        return check(2*a);
    return check(2*a+1);
}
void wywal(int a)
{
    if(tab[2*a]==0 && tab[2*a+1]==0)
    {
       tab[a]=0;
       return;
    }
    if(tab[2*a]>tab[2*a+1])
    {
        tab[a]=tab[2*a];
        wywal(2*a);
        return;
    }
    tab[a]=tab[2*a+1];
    wywal(2*a+1);
}
void zrob(int a)
{
    if(tab[a]==0)
        return;
    while(check(a)>b)
    {
        wywal(a);
        v.push_back(a);
    }
    zrob(2*a);
    zrob(2*a+1);
}
void solve()
{
    int a;
    cin>>a>>b;
    a=(1<<a)-1;
    b=(1<<b)-1;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    zrob(1);
    long long suma=0;
    for(int x=1;x<=b;x++)
        suma+=tab[x];
    cout<<suma<<'\n';
    for(auto x:v)
        cout<<x<<" ";
    cout<<'\n';
    v.resize(0);
    for(int x=1;x<=a;x++)
        tab[x]=0;
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