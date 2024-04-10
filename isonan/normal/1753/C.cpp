#include <bits/stdc++.h>

std::vector<std::pair<int,int> >ans;
int t,n,a[500001],x,cnt[500001];
const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int m=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]==0)++m;
		}
		int x=0;
		for(int i=1;i<=m;++i)if(a[i]==1)++x;
		int ans=0;
		for(int i=1;i<=x;++i)ans=add(ans,qsm(mul(i,i),P-2));
		printf("%d\n",mul(ans,((1ll*n*(n-1))/2)%P));
	}
}