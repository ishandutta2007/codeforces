#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,mx[100500],mn[100500],sb[100500],a[100500],b[100500],it;
ll res,r2;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		mn[i]=1145141919;
		it=1;
		for(j=1;j<=m;j++){
			scanf("%d",&k);
			if(k>mn[i]){sb[i]=1;}
			mx[i]=max(mx[i],k);
			mn[i]=min(mn[i],k);
		}
		r2+=sb[i];
	}
	res+=1ll*n*n-1ll*(n-r2)*(n-r2);it=0;
	for(i=1;i<=n;i++){
		if(sb[i]){continue;}
		it++;
		a[it]=mn[i];b[it]=mx[i];
		//if(mn[i]<mx[i]){res--;}
	}
	sort(a+1,a+it+1);sort(b+1,b+it+1);
	i=j=1;
	for(;i<=it;i++){
		while(a[i]>=b[j]){
			j++;if(j>it){goto aaa;}
		}
		res+=it-j+1;
	}
	aaa:;
	printf("%lld",res);
	
}