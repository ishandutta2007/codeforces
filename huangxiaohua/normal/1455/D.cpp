#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define M 1000000007

int i,j,k,n,t,a[505],res;
vector<int> v;

int chk(int sb,int k){
	v.clear();
	int tmp=0,i,tmp2=k;
	for(i=1;i<=n+1;i++){
		if(i==sb){continue;}
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	for(i=1;i<=n;i++){
		if(v[i-1]!=a[i]){
			if(a[i]<=k){
				return 99999;
			}
			tmp++;k=a[i];
		}
	}
	return tmp;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		res=9999;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		j=0;
		for(i=2;i<=n;i++){
			if(a[i]<a[i-1]){j=1;}
		}
		if(!j){puts("0");continue;}
		a[n+1]=k;
		for(i=1;i<=n;i++){
			res=min(res,chk(i,k));
		}
		
		if(res==9999){puts("-1");continue;}
		printf("%d\n",res);
	}
}