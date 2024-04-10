#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
void init(){
	return;
}
int n,K;
vector<int> c[110];
int cnt;
int q[110];
void change(int k,int z){
	for(int i=1;i<=z;++i){
		for(int j=1;j<cnt;++j){
			if(c[q[j]][k]<c[q[j+1]][k]){
				swap(q[j],q[j+1]);
			}
		}
	}
	return;
}
int ans[110][2];
void MAIN(){
	int u,v;
	int x,y,z;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n*K;++i){
		scanf("%d",&x);
		c[x].push_back(i);
	}
	for(int i=1;i<=n;++i) q[i]=i;
	cnt=n;
	int lim=(n+K-2)/(K-1);
	for(int i=1,j,k=1;i<=n;i=j+1,++k){
		j=i;
		while(j<n&&j-i+1<lim) ++j;
		z=j-i+1;
		change(k,z);
		while(z--){
			ans[q[cnt]][0]=c[q[cnt]][k-1];
			ans[q[cnt]][1]=c[q[cnt]][k];
			//printf("%d %d\n",c[q[cnt]][k-1],c[q[cnt]][k]);
			--cnt;
		}
	}
	for(int i=1;i<=n;++i) printf("%d %d\n",ans[i][0],ans[i][1]);
	return;
}
int main(){
	init();
	int ttt=1;//ttt=read();
	while(ttt--) MAIN();
	return 0;	
}