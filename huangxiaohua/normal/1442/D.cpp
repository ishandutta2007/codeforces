#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,sb[3050],nmsl;
ll sum[3050],res;
vector<ll> v,a[3050];

void chk(int l,int r,vector<ll> vl,vector<ll> vr){
	int i,md=(l+r)/2,j;
	ll tmp=0;
	if(l==r){
		for(i=0;i<=min(k,sb[l]);i++){
			//printf("%d %d %d %d\n",l,i,tmp,vl[k-i]);
			res=max(res,tmp+vl[k-i]);tmp+=a[l][i+1];
		}
		return;
	}
	for(i=l;i<=md;i++){
		for(j=k;j-sb[i]>=0;j--){
			vl[j]=max(vl[j],vl[j-sb[i]]+sum[i]);
		}
	}
	for(i=md+1;i<=r;i++){
		for(j=k;j-sb[i]>=0;j--){
			vr[j]=max(vr[j],vr[j-sb[i]]+sum[i]);
		}
	}
	chk(l,md,vr,vr);
	chk(md+1,r,vl,vl);
}

int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=3050;i++){
		v.push_back(0);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
		a[i].push_back(0);
		for(j=1;j<=sb[i];j++){
			scanf("%d",&nmsl);
			sum[i]+=nmsl;
			a[i].push_back(nmsl);
		}
		a[i].push_back(0);
	}
	chk(1,n,v,v);
	printf("%lld",res);
}