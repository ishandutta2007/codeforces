#include<bits/stdc++.h>
using namespace std;
int perm[1000005];
int dok[1000005];
vector<int> gdzie[1000005];
int tab[1000005];
vector<int> pol[1000005];
int skoki[25][200005];
bool odw[200005];
int pot=1<<20;
int drzewo[4000005];
void ins(int a,int b)
{
    int pom=a+pot;
    while(pom!=0)
    {
        drzewo[pom]=min(drzewo[pom],b);
        pom/=2;
    }
}
int check(int a,int b)
{
    int war=1e9,l=a+pot,r=b+pot;
    war=drzewo[l];
    if(l!=r)
        war=min(war,drzewo[r]);
    while(l/2!=r/2)
    {
        if(l%2==0)
            war=min(war,drzewo[l+1]);
        if(r%2==1)
            war=min(war,drzewo[r-1]);
        l/=2;
        r/=2;
    }
    return war;
}
void dfs(int a)
{
	for(auto x:pol[a])
    {
        if(!odw[x])
        {
            skoki[0][x]=a;
            odw[x]=true;
            dfs(x);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,t;
    cin>>a>>b>>t;
    for(int x=0;x<a;x++)
        cin>>perm[x];
    for(int x=0;x<a;x++)
        dok[perm[x]]=perm[(x+1)%a];
    for(int x=0;x<b;x++)
    {
        cin>>tab[x];
        gdzie[tab[x]].push_back(x);
    }
    for(int x=1;x<=a;x++)
        gdzie[x].push_back(b);
    for(int x=0;x<b;x++)
    {
        pol[x].push_back(*lower_bound(gdzie[dok[tab[x]]].begin(),gdzie[dok[tab[x]]].end(),x));
        pol[*lower_bound(gdzie[dok[tab[x]]].begin(),gdzie[dok[tab[x]]].end(),x)].push_back(x);
    }
    odw[b]=true;
    dfs(b);
    skoki[0][b]=b;
    for(int i = 1; i < 21; i++)
		for(int j = 0; j <= b; j++)
			skoki[i][j]=skoki[i-1][skoki[i-1][j]];
    for(int x=0;x<=4000000;x++)
        drzewo[x]=1e9;
    int pom=a-1,pom1,pom2,pom3;
    for(int x=0;x<b;x++)
    {
        pom1=x;
        pom2=1;
        pom3=0;
        while(pom2<2*1e6)
        {
            if((pom2&pom)!=0)
                pom1=skoki[pom3][pom1];
            pom3++;
            pom2*=2;
        }
        ins(x,pom1);
    }
    int c,d;
    while(t--)
    {
        cin>>c>>d;
        if(check(c-1,d-1)<=d-1)
            cout<<1;
        else
            cout<<0;
    }



	return 0;
}