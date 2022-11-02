#include<bits/stdc++.h>
using namespace std;
int tab[2000005];
int tree[2000005];
int pot=(1<<19);
set<pair<int,int>> s;
void ins(int a,int b)
{
    int pom=b+pot;
    while(pom!=0)
    {
        tree[pom]=min(tree[pom],a);
        pom/=2;
    }
}
int check(int a,int b)
{
    int l=a+pot,r=b+pot;
    int war=tree[l];
    if(l!=r)
        war=min(war,tree[r]);
    while(l/2!=r/2)
    {
        if(l%2==0)
            war=min(war,tree[l+1]);
        if(r%2==1)
            war=min(war,tree[r-1]);
        l/=2;
        r/=2;
    }
    return war;
}
void pre()
{
    for(int x=0;x<2e6;x++)
        tree[x]=1e9+1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
    int a,mini=1e9+1,maks=-1;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        mini=min(mini,tab[x]);
        maks=max(maks,tab[x]);
    }
    if(2*mini>=maks)
    {
        while(a--)
            cout<<-1<<" ";
        return 0;
    }
    for(int x=0;x<a;x++)
    {
        tab[x+a]=tab[x];
        tab[x+2*a]=tab[x];
    }
    for(int x=0;x<3*a;x++)
    {
        s.insert(make_pair(-tab[x],x));
        int pom=2*tab[x];
        while(-(*s.begin()).first>pom)
        {
            ins(x,(*s.begin()).second);
            s.erase(s.begin());
        }
    }
   // return 0;
    for(int x=0;x<a;x++)
        cout<<check(x,3*a-1)-x<<" ";
	return 0;
}