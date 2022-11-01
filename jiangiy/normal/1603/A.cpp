#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100010;
int n,a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		bool ans=1;
		for(int i=1;i<=std::min(n,100);i++){
			bool flag=0;
			for(int j=1;j<=i;j++) if(a[i]%(j+1)!=0){
				flag=1;
				break;
			}
			ans&=flag;
		}
		puts(ans?"YES":"NO");
	}
}