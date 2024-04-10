#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
int i,j,k,n,m;
vector<int> v[50050];
ll res,jc[25]={1},tmp,sb[25],inv;

int main(){
	for(i=1;i<=20;i++){
		jc[i]=jc[i-1]*i%M;
	}
	scanf("%d%d",&n,&m);
	res=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&k);
			v[j].push_back(k);
		}
	}
	inv=ksm(jc[n],M-2);
	for(i=1;i<=m;i++){
		v[i].push_back(0);
		sort(v[i].begin(),v[i].end());
		for(j=1;j<=n;j++){
			v[i][j]--;
		}
		memset(sb,0,sizeof(sb));
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(v[i][j]>=k){sb[k]++;}
			}
		}
		tmp=1;
		for(j=1;j<=n;j++){
			sb[j]-=(n-j);
			if(sb[j]<=0){tmp=0;break;}
			tmp=tmp*sb[j]%M;
		}
		//printf("%d %d\n",jc[n],tmp);
		tmp=(jc[n]+M-tmp)%M*inv%M;
		res+=tmp;
	}
	printf("%lld",res%M);
}