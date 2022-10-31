#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1ll<<((x)-1))
#define M 1000000007

int i,j,k,n,m,t,x,y,vis[200500],it2;
ll w,b[66],num[66],tmp[66],dis[6666666],res,siz,it;
vector<pair<int,ll> >v[200500];

void add(ll x){
	for(int i=61;i>=1;i--){
		if(x&b(i)){
			if(b[i]){x^=b[i];}
			else{b[i]=x;it++;break;}
		}
	}
}

void upd(){
	int i,j;
	for(i=1;i<=61;i++){
		for(j=i+1;j<=61;j++){
			if(b[j]&b(i)){b[j]^=b[i];}
		}
	}
}

void dfs(int x,int fa){
	int i,j,k;
	vis[x]=1;
	siz++;
	if(x!=fa){
		for(i=61;i>=1;i--){
			if(dis[x]&b(i)){num[i]++;}
		}
	}
	for(auto [i,j]:v[x]){
		if(vis[i]){
			add(dis[i]^dis[x]^j);
		}
		else{
			dis[i]=dis[x]^j;
			dfs(i,fa);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&w);
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	for(i=1;i<=n;i++){
		if(vis[i]){continue;}
		siz=0;it=0;
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		dfs(i,i);
		upd();
		for(j=1;j<=61;j++){
			it2=0;
			for(k=1;k<=61;k++){
				if(b[k]&b(j)){it2=1;break;}
			}
			if(it2){
				res=(res+((siz*siz-siz)/2)%M*(b(j)%M)%M*(b(it)%M)%M)%M;
			}
			else{
				res=(res+num[j]%M*(siz-num[j])%M*(b(j)%M)%M*(b(it+1)%M)%M)%M;
			}
		}
	}
	printf("%lld",res);
}