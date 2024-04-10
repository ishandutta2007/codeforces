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
int n,Q;
bool is_pri[1000000+10];
int pri[100000],cntp=0;
int b[1000000+10];
int a[160000];
int fa[100000];
int tp;
int q[100];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
map<int, map<int,int> > mp;
void MAIN(){
	int x,y;
	for(int i=2;i<=1000001;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
            b[i]=cntp;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=1000001;++j){
            is_pri[pri[j]*i]=1;
            b[pri[j]*i]=j;
            if(i%pri[j]==0) {
                break;
            }
        }
    }
    for(int i=1;i<=cntp;++i) fa[i]=i;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		tp=0;
		x=a[i];
		while(x>1){
			y=b[x];
			q[++tp]=y;
			while(x%pri[y]==0) x/=pri[y];
		}
		for(int i=2;i<=tp;++i){
			x=find(q[1]);
			y=find(q[i]);
			if(x==y) continue;
			fa[y]=x;
		}
	}
	mp.clear();
	for(int i=1;i<=n;++i){
		tp=0;
		x=a[i];
		if(x>1){
			y=b[x];
			q[++tp]=y;
		}
		x=a[i]+1;
		while(x>1){
			y=b[x];
			q[++tp]=y;
			while(x%pri[y]==0) x/=pri[y];
		}
		for(int j=1;j<=tp;++j){
			q[j]=find(q[j]);
		}
		if(tp<=1) continue;
		sort(q+1,q+1+tp);
		x=1;
		for(int j=2;j<=tp;++j){
			if(q[j]!=q[x]) q[++x]=q[j];
		}
		tp=x;
		for(int j=1;j<=tp;++j)
			for(int k=j+1;k<=tp;++k){
				mp[q[j]][q[k]]=1;
			}
	}
	while(Q--){
		scanf("%d%d",&x,&y);
		x=a[x];y=a[y];
		x=b[x];y=b[y];
		x=find(x);y=find(y);
		if(x==y){
			puts("0");
			continue;
		}
		if(x>y) swap(x,y);
		if(mp[x][y]) {
			puts("1");
			continue;
		}
		puts("2");
	}
	return;
}
int main(){
	init();
	int ttt=1;//ttt=read();
	while(ttt--) MAIN();
	return 0;	
}