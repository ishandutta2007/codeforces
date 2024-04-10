#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=105;
int n,s[N];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<1<<n;j++){
				if(j>>i-1&1)continue;
				for(int k=j;;k=k-1&j){
					int t=0;
					for(int l=0;l<n;l++){
						if(j>>l&1){
							t+=(k>>l&1)?s[l+1]:-s[l+1];
						}
					}
					if(t==s[i])flag=1;
					if(!k)break;
				}
			}
		}
		puts(flag?"YES":"NO");
	}
}