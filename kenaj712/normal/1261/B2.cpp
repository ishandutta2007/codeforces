#include<bits/stdc++.h>
using namespace std;
int pot=(1<<19);
int tree[2000005];
int tab[1000005];
vector<pair<int,int>> v[1000005];
int odp[1000005];
vector<pair<int,int>> v2;
void ins(int a)
{
    int pom=a+pot;
    while(pom!=0)
    {
        tree[pom]++;
        pom/=2;
    }
}
int check(int a,int b)
{
    int l=a+pot,r=b+pot;
    int sum=tree[l];
    if(l!=r)
        sum+=tree[r];
    while(l/2!=r/2)
    {
        if(l%2==0)
            sum+=tree[l+1];
        if(r%2==1)
            sum+=tree[r-1];
        l/=2;
        r/=2;
    }
    return sum;
}
int bins(int a)
{
    int pocz=0,kon=2e5+1,sr;
    while(pocz!=kon)
    {
        sr=(pocz+kon)/2;
        if(check(0,sr)>=a)
            kon=sr;
        else
            pocz=sr+1;
    }
    return tab[pocz];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,e;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        v2.push_back(make_pair(tab[x],-x));
    }
    sort(v2.begin(),v2.end());
    int t,c,d;
    cin>>t;
    for(int x=0;x<t;x++)
    {
        cin>>c>>d;
        v[c].push_back(make_pair(d,x));
    }
    for(int x=1;x<=a;x++)
    {
        ins(-v2.back().second);
        v2.pop_back();
        for(auto y:v[x])
            odp[y.second]=bins(y.first);
    }
    for(int x=0;x<t;x++)
        cout<<odp[x]<<'\n';
	return 0;
}