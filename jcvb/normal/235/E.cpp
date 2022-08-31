#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c;
int pr[310],bo[2005]={0},ptot=0;
int fa[90],ta[2005],an;
int fb[90],tb[2005],bn;
int fc[90],tc[2005],cn;
void pre(int a,int *fa,int *ta,int &tot){
     tot=0;
	for (int j=1,nex;j<=a;j=nex+1){
		nex=a/(a/j);
		fa[++tot]=a/j;
	}
	for (int i=1;i<tot-i+1;i++)swap(fa[i],fa[tot-i+1]);
	for (int i=1;i<=tot;i++)ta[fa[i]]=i;
}
int f[100][90][90][90];
int f1[210][10][10][10];
int F(int t,int i,int j,int k){
    if(t==0)return 1;
    if(t<100){
              if(~f[t][i][j][k])return f[t][i][j][k];
    }else{
          if(~f1[t-100][i==an?9:i][j==bn?9:j][k==cn?9:k])return f1[t-100][i==an?9:i][j==bn?9:j][k==cn?9:k];
    }
    int ans=0;
    for (int xa=fa[i],x=0;xa;xa/=pr[t],x++)
        for (int yb=fb[j],y=0;yb;yb/=pr[t],y++)
            for (int zc=fc[k],z=0;zc;zc/=pr[t],z++){
                ans+=(1+x+y+z)*F(t-1,ta[xa],tb[yb],tc[zc]);
            }
    if(t<100){
              return f[t][i][j][k]=ans&(~(3<<30));
    }else{
         return f1[t-100][i==an?9:i][j==bn?9:j][k==cn?9:k]=ans&(~(3<<30));
    }
}
int main()
{
    memset(f,-1,sizeof(f));
    memset(f1,-1,sizeof(f1));
	scanf("%d%d%d",&a,&b,&c);
	for (int i=2;i<=2000;i++)if(!bo[i]){
		pr[++ptot]=i;
		for (int j=i+i;j<=2000;j+=i)bo[j]=1;
	}
	pre(a,fa,ta,an);
	pre(b,fb,tb,bn);
	pre(c,fc,tc,cn);
    printf("%d\n",F(ptot,an,bn,cn));
	return 0;
}