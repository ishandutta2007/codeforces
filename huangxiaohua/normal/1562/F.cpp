#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,vis[200500],mn;ll res[200500];
#define NMSL memset(res,0,sizeof(res));
map<ll,int> mp;
ll sb,f[105][105];
vector<int> p;

struct SB{
	ll l,r,w;
	bool operator<(const SB x)const{return w>x.w;}
}f2[5050];

void solve(ll l,ll r){
	NMSL;
	r--;
	ll i,j,k;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(f[i][j]==r*r-r){res[i]=res[j]=1;break;}
		}
	}
	r++;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(f[i][j]==r*r-r){
				if(!res[i]){memset(res,0,sizeof(res));res[i]=r;goto aaa;}
				if(!res[j]){memset(res,0,sizeof(res));res[j]=r;goto aaa;}
				exit(1);
			}
		}
	}
	aaa:;
	for(i=r-1;i>=l;i--){
		for(j=1;j<=n;j++){
			for(k=j+1;k<=n;k++){
				if(f[j][k]==i*i+i){
					if(res[j]==i+1&&!res[k]){res[k]=i;goto aa;}
					if(res[k]==i+1&&!res[j]){res[j]=i;goto aa;}
				}
			}
		}
		aa:;
	}
	printf("! ");for(i=1;i<=n;i++){printf("%d ",res[i]);}puts("");fflush(stdout);
	return;
}
 
void get1(){
	memset(vis,0,sizeof(vis));
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			printf("? %d %d\n",i,j);fflush(stdout);
			scanf("%lld",&sb);
			f[i][j]=sb;
			if(mp.count(sb)){
				k=mp[sb];
				vis[k]++;
			}
		}
	}
	j=0;
	for(i=200000;i>=1;i--){
		if(vis[i]){
			if(!j){j=i;}
			if(j-i+1==n-1){
				solve(i,j+1);return;
			}
		}
		else{
			j=0;
		}
	}
}

void get2(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim(1,n);
	ll sb=1,i,j,k,cur,res2;
	for(i=1;i<=4800;i++){
		j=lim(rng);k=lim(rng);
		if(j==k){i--;continue;}
		printf("? %lld %lld\n",j,k);fflush(stdout);
		scanf("%lld",&f2[i].w);
		f2[i].l=j;f2[i].r=k;
	}
	sort(f2+1,f2+4800+1);
	for(i=1;i<=200;i++){
		for(auto j:p){
			if(f2[i].w<=sb){break;}
			if(!(f2[i].w%j)){
				if(j>sb){
					sb=j;cur=i;
				}
				while(!(f2[i].w%j)){f2[i].w/=j;}
			}
		}
	}
	j=f2[cur].l;k=lim(rng);
	while(k==j){k=lim(rng);}
	printf("? %lld %lld\n",j,k);fflush(stdout);
	scanf("%lld",&i);
	if(!(i%sb)){res2=j;}else{res2=f2[cur].r;}
	for(i=1;i<=n;i++){
		if(i==res2){res[i]=sb;continue;}
		printf("? %lld %lld\n",res2,i);fflush(stdout);
		scanf("%lld",&res[i]);
		res[i]/=sb;
	}
	printf("! ");for(i=1;i<=n;i++){printf("%d ",res[i]);}puts("");fflush(stdout);
}
 
int main() {
	for(i=2;i<=200000;i++){
		if(!vis[i]){
			p.push_back(i);
			for(j=i+i;j<=200000;j+=i){vis[j]=1;}
		}
	}
	for(ll i=1;i<=200000;i++){
		mp[i*(i+1)]=i;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=99){
			get1();
		}
		else{
			get2();
		}
	}
}