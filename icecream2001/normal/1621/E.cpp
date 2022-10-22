#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=3e5+10;
const int INF=2e9;
void init(){
}

int n,K,m;
LL a[N];
int b[N];
vector<LL> V[N];
int find(LL x,LL y){
	int l=0,r=n,mid;
	while(l!=r){
		mid=(l+r+1)>>1;
		if(a[mid]*y>=x) l=mid;
		else r=mid-1;
	}
	return l;
}
set<int> S;
set<int>::iterator it;
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1,j=n;i<j;i++,j--){
		swap(a[i],a[j]);
	}
	for(int i=0;i<=n;++i){
		b[i]=0;
	}
	LL x,sum;
	int id;
	for(int i=1;i<=m;++i){
		V[i].clear();
		scanf("%d",&K);sum=0;
		for(int j=1;j<=K;++j){
			scanf("%lld",&x);
			V[i].push_back(x);
			sum+=x;
		}
		id=find(sum,(LL)K);
		++b[id];
	}
	for(int i=1;i<=n;++i) b[i]+=b[i-1];
	int flag=0,l,r;
	for(int i=0;i<=n;++i){
		flag=max(flag,b[i]-i);
	}
	if(flag>=2){
		for(int i=1;i<=m;++i){
			for(int j=0;j<V[i].size();++j){
				putchar('0');
			}
		}
		puts("");
		return;
	}
	if(flag==1){
		for(int i=0;i<=n;++i){
			if(b[i]-i==1){
				l=i;break;
			}
		}
		for(int i=n;i>=0;--i){
			if(b[i]-i==1){
				r=i;break;
			}
		}
		for(int i=1;i<=m;++i){
			sum=0;K=V[i].size();
			for(int j=0;j<K;++j){
				sum+=V[i][j];
			}
			id=find(sum,(LL)K);
			if(id>l){
				for(int j=0;j<K;++j){
					putchar('0');
				}
				continue;
			}
			for(int j=0;j<K;++j){
				id=find(sum-V[i][j],(LL)(K-1));
				if(id<=r) putchar('0');
				else putchar('1');
			}
		}
		puts("");
		return;
	}
	S.clear();
	for(int i=0;i<=n;++i){
		if(b[i]==i){
			S.insert(i);
		}
	}
	for(int i=1;i<=m;++i){
		sum=0;K=V[i].size();
		for(int j=0;j<K;++j){
			sum+=V[i][j];
		}
		r=find(sum,(LL)K);
		for(int j=0;j<K;++j){
			id=find(sum-V[i][j],(LL)(K-1));
			it=S.lower_bound(id);
			if(it==S.end()){
				putchar('1');
			}
			else{
				if((*it)<r) putchar('0');
				else putchar('1');
			} 
		}
	}
	puts("");
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}