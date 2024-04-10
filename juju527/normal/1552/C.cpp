#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int e[maxn][2],p[2*maxn];
bool use[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n,k;
		n=read();k=read();
		for(int i=1;i<=2*n;i++)use[i]=0;
		for(int i=1;i<=k;i++){
			int x,y;
			x=read();y=read();
			if(x>y)swap(x,y);
			e[i][0]=x,e[i][1]=y;
			use[x]=use[y]=1;
		}
		int len=0;
		for(int i=1;i<=2*n;i++)if(!use[i])p[++len]=i;
		for(int i=1;i<=len/2;i++)++k,e[k][0]=p[i],e[k][1]=p[i+len/2];
		int res=0;
		for(int i=1;i<=k;i++){
			int x1=e[i][0],y1=e[i][1];
			for(int j=i+1;j<=k;j++){
				int x2=e[j][0],y2=e[j][1];
				if(x1>y2||x2>y1||(x1<x2&&y1>y2)||(x2<x1&&y2>y1))continue;
				res++;
			}
		}
		printf("%d\n",res);
	}
    return 0;
}