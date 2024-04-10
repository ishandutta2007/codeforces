#include <bits/stdc++.h>
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
int n,m;
vector<int> a[N];
int p[N],q[N],ans[N];
int tp;
int t[N];
int b[N];
int vis[N];
int E,D;
vector< pair<int,int> >C;
void MAIN(){
	int x,mx,y,z;
    scanf("%d%d",&n,&m);
    if(m==1){
    	puts("Yes");
    	puts("1");
    	return;
	}
	if(m==2){
		puts("Yes");
    	puts("1 1");
    	return;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	for(int j=0;j<m;++j){
		mx=0;
		for(int i=1;i<=n;++i) t[i]=a[i][j];
		sort(t+1,t+1+n);
		for(int i=1,k;i<=n;i=k+1){
			k=i;
			while(k+1<=n&&t[k+1]==t[i]) ++k;
			if(k-i+1>mx){
				mx=k-i+1;
				p[j]=t[i];
			}
		}
	}
	mx=0;y=0;
	for(int i=1;i<=n;++i){
		z=0;
		for(int j=0;j<m;++j){
			if(a[i][j]!=p[j]){
				++z;
			}
		}
		if(z>mx){
			mx=z;
			y=i;
		}
	}
	if(mx<=2){
		puts("Yes");
		for(int j=0;j<m;++j) printf("%d ",p[j]);
		return;
	}
	if(mx>=8){
		puts("No");
		return;
	}
	tp=0;
	for(int j=0;j<m;++j){
		if(a[y][j]!=p[j]){
			b[++tp]=j;
		}
	}
	bool flag,re=0;
	for(int d=1;d<=tp;++d){
		for(int e=1+d;e<=tp;++e){
			if(re) continue;
			flag=0;
			for(int i=1;i<=n;++i) vis[i]=0;
			for(int j=0;j<m;++j){
				if(j!=b[d]&&j!=b[e]){
					q[j]=a[y][j];
					for(int i=1;i<=n;++i)
						if(a[i][j]!=q[j]) ++vis[i];
				}
			}
			for(int i=1;i<=n;++i) if(vis[i]>2) flag=1;
			if(flag==1) continue;
			D=0;E=0;C.clear(); 
			for(int i=1;i<=n;++i){
				if(vis[i]==2){
					if(D!=0&&D!=a[i][b[d]]) flag=1;
					if(E!=0&&E!=a[i][b[e]]) flag=1;
					D=a[i][b[d]];
					E=a[i][b[e]];
				}
				if(vis[i]==1){
					C.push_back(make_pair(a[i][b[d]],a[i][b[e]]));
				}
			}
			if(flag==1) continue;
			if(D&&E){
				for(int k=0;k<C.size();++k){
					if(C[k].first!=D&&C[k].second!=E){
						flag=1;
					}
				}
				if(!flag){
					re=1;
					for(int k=0;k<m;++k){
						if(k!=b[d]&&k!=b[e])ans[k]=a[y][k];
						if(k==b[d])ans[k]=D;
						if(k==b[e])ans[k]=E;
					}
				}
			}
			else if(C.size()==0){
				re=1;
				for(int k=0;k<m;++k){
					ans[k]=a[y][k];
				}
			}
			else{
				flag=0;
				D=C[0].first;E=0;
				for(int k=0;k<C.size();++k){
					if(C[k].first==D||C[k].second==E)continue;
					if(E!=0) flag=1;
					E=C[k].second;
				}
				if(flag==0){
					re=1;
					for(int k=0;k<m;++k){
						if(k!=b[d]&&k!=b[e])ans[k]=a[y][k];
						if(k==b[d])ans[k]=D;
						if(k==b[e]&&E!=0)ans[k]=E;
						if(k==b[e]&&E==0)ans[k]=1;
					}
					continue;
				}
				flag=0;
				D=0;E=C[0].second;
				for(int k=0;k<C.size();++k){
					if(C[k].first==D||C[k].second==E)continue;
					if(D!=0) flag=1;
					D=C[k].first;
				}
				if(flag==0){
					re=1;
					for(int k=0;k<m;++k){
						if(k!=b[d]&&k!=b[e])ans[k]=a[y][k];
						if(k==b[d]&&D!=0)ans[k]=D;
						if(k==b[d]&&D==0)ans[k]=1;
						if(k==b[e])ans[k]=E;
					}
					continue;
				}
			}
		}
	}
	if(re){
		puts("Yes");
		for(int j=0;j<m;++j) printf("%d ",ans[j]);
		puts("");
	}
	else{
		puts("No");
	}
    return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}