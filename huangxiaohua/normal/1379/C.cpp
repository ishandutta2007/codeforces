#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
vector<pair<ll,ll> > v;
ll res,p[200500],a[200500],tmp;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		v.clear();
		for(i=1;i<=m;i++){
			scanf("%d%d",&j,&k);v.push_back({-k,j});a[i]=-j;
		}
		sort(v.begin(),v.end());
		sort(a+1,a+m+1);
		for(i=1;i<=m;i++){
			a[i]=-a[i];p[i]=p[i-1]+a[i];
		}
		k=0;res=0;
		for(auto [i,j]:v){
			i=-i;
			while(k<=min(n-2,m-1)&&a[k+1]>i){k++;}
			if(k<n&&k<m&&a[k+1]<=j&&a[k+1]>i){k++;}
			if(!k||a[k]>j){tmp=p[k]+j+i*(n-1-k);}
			else{tmp=p[k]+i*(n-k);}
			res=max(res,tmp);
			if(k){k--;}
			//printf("%d %d %d %lld\n",i,j,k,res);
		}
		printf("%lld\n",res);
	}
}