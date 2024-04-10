#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];
ll sum,res[200500],tmp[200500],b[200500];
vector<int> v[200500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sum=0;
		for(i=1;i<=n;i++){v[i].clear();res[i]=0;b[i]=0;}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			v[a[i]].push_back(k);
			sum+=k;
		}
		for(i=1;i<=n;i++){
			res[i]=sum;
		}
		for(i=1;i<=n;i++){
			m=v[i].size();
			if(!m){continue;}
			sort(v[i].begin(),v[i].end());
			for(j=1;j<=m;j++){
				tmp[j]=tmp[j-1]+v[i][j-1];
			}
			for(j=1;j<=m;j++){
				res[j]-=tmp[m%j];
			}
			b[m+1]+=tmp[m];
		}
		sum=0;
		for(i=1;i<=n;i++){
			sum+=b[i];
			printf("%lld ",res[i]-sum);
		}puts("");
	}
}