#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const double eps=1e-6;
const int inf=1e9;
const int P=998244353;
const int N=1e3+10;

int n,m; 
int a[N][N];
int b[N];
int th[N],tl[N];
int h[N][N],l[N][N];
map<int,int> mp;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=m;++j){
    		scanf("%d",&a[i][j]);
		}
	}
	int x;
	for(int i=1;i<=n;++i){
		mp.clear();x=0;
		for(int j=1;j<=m;++j)
			b[j]=a[i][j];
		sort(b+1,b+m+1);
		for(int j=1;j<=m;++j)
			if(!mp[b[j]]) mp[b[j]]=++x;
		th[i]=x;
		for(int j=1;j<=m;++j)
			h[i][j]=mp[a[i][j]];
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j) cout<<h[i][j]<<" ";cout<<endl;
//	}
	for(int j=1;j<=m;++j){
		mp.clear();x=0;
		for(int i=1;i<=n;++i)
			b[i]=a[i][j];
		sort(b+1,b+n+1);
		for(int i=1;i<=n;++i)
			if(!mp[b[i]]) mp[b[i]]=++x;
		tl[j]=x;
		for(int i=1;i<=n;++i)
			l[i][j]=mp[a[i][j]];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			x=max(h[i][j]-1,l[i][j]-1)+max(th[i]-h[i][j],tl[j]-l[i][j])+1;
			printf("%d ",x);
		}
		puts("");
	}
}
/*
3 2
554 727
467 591
603 609

5 8
2 588
749 791
502 819
148 456
79 571
*/