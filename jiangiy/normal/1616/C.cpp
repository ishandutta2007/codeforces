#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=80;
int n,s[N];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		int ans=1;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			int ta=2;
			for(int k=1;k<=n;k++) if(k!=i&&k!=j){
				ta+=(s[k]-s[i])*(j-i)==(s[j]-s[i])*(k-i);
			}
			ans=std::max(ans,ta);
		}
		printf("%d\n",n-ans);
	}
}