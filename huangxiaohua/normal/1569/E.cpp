#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,it,sb,sb2;
ll p,h,a[67],res[66],rd;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
map<int,vector<int> >mp;

int get(int l,int r,int x,int dep,int w){
	if(l==r){return l;}
	int md=(l+r)/2;
	int xx,yy;
	xx=get(l,md,x,dep+1,w+b(dep));
	yy=get(md+1,r,x,dep+1,w+b(dep));
	it++;
	if(dep==1){
		if(b(it)&x){res[xx]=sb;res[yy]=sb2;}
		else{res[yy]=sb;res[xx]=sb2;}
		return 0;
	}
	if(b(it)&x){res[yy]=w;return xx;}
	else{res[xx]=w;return yy;}
}

void baoli(){
	rd=(1<<n)-1;
	for(i=0;i<b(rd+1);i++){
		memset(res,0,sizeof(res));it=0;
		get(1,rd+1,i,1,2);
		ll ans=0;
		for(j=1;j<=rd+1;j++){
			ans=su(ans,a[res[j]]*j%M);
		}
		if(ans==h){
			for(j=1;j<=rd+1;j++){
				printf("%d ",res[j]);
			}exit(0);
		}
	}
}

int get2(int l,int r,int x,int dep,int w){
	if(l==r){return l;}
	int md=(l+r)/2;
	int xx,yy;
	xx=get2(l,md,x,dep+1,w+b(dep+1));
	yy=get2(md+1,r,x,dep+1,w+b(dep+1));
	it++;
	if(dep==1){
		if(b(it)&x){
			res[xx]=sb;res[yy]=3;
		}
		else{
			res[yy]=sb;res[xx]=3;
		}
		return 0;
	}
	if(b(it)&x){
		res[yy]=w;return xx;
	}
	else{
		res[xx]=w;return yy;
	}
}

void baoli2(int x){
	rd=15;
	sb=3-x;
	mp.clear();
	for(i=0;i<b(16);i++){
		memset(res,0,sizeof(res));it=0;
		get2(1,16,i,1,3);
		ll ans=0;
		vector<int> v;
		for(j=1;j<=16;j++){
			ans=su(ans,a[res[j]]*j%M);
			v.push_back(res[j]);
		}
		mp[ans]=v;
	}
	sb=x;
	for(i=0;i<b(16);i++){
		memset(res,0,sizeof(res));it=0;
		get2(1,16,i,1,3);
		ll ans=0,ans2=0;
		vector<int> v;
		for(j=1;j<=16;j++){
			ans2=su(ans2,a[res[j]]*(j+16)%M);
			v.push_back(res[j]);
		}
		ans=su(h,M-ans2);
		if(mp.count(ans)){
			for(auto j:mp[ans]){printf("%d ",j);}
			for(auto j:v){printf("%d ",j);}
			exit(0);
		}
	}
}

int main(){
	scanf("%d%lld%lld",&n,&p,&h);
	a[0]=1;
	for(i=1;i<=50;i++){
		a[i]=a[i-1]*p%M;
	}
	sb=1;sb2=2;
	if(n<=4){
		baoli();
		puts("-1");
		return 0;
	}
	sb2=3;
	baoli2(1);baoli2(2);
	puts("-1");
}