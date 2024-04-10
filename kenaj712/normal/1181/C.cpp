#include<bits/stdc++.h>
using namespace std;
int pot=(1<<22);
int drzewo[10000005];
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
    int l=a+pot,r=b+pot,war;
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
void pre()
{
    for(int x=0;x<=1e7;x++)
        drzewo[x]=1e6;
}
char tab[3005][3005];
int dol[3005][3005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    pre();
    int a,b,pom,pom1,pom2,pom3;
    cin>>a>>b;
    long long out=0;
    for(int x=0;x<=a+1;x++)
        for(int y=0;y<=b+1;y++)
            tab[x][y]='+';
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
            cin>>tab[x][y];
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=b;y++)
        {
            pom=y;
            while(tab[x][y]==tab[x][pom])
                pom++;
            pom--;
            for(int z=y;z<=pom;z++)
                ins(1001*z+x,pom);
            y=pom;
        }
    }
    for(int y=1;y<=b;y++)
    {
        for(int x=1;x<=a;x++)
        {
            pom=x;
            while(tab[x][y]==tab[pom][y])
                pom++;
            pom--;
            for(int z=x;z<=pom;z++)
                dol[z][y]=pom;
            x=pom;
        }
    }
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            pom=dol[x][y]-x+1;
            if(pom!=dol[x+pom][y]-x-pom+1||pom>dol[x+2*pom][y]-x-2*pom+1)
                continue;
            //cout<<1001*y+x<<" "<<1001*y+x+3*pom-1<<" "<<check(1001*y+x,1001*y+x+3*pom-1)<<'\n';
            out+=check(1001*y+x,1001*y+x+3*pom-1)-y+1;
        }
    cout<<out;
	return 0;
}