#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200005;
bool ans[N];
void solve(int a,int b){
	int n=a+b;
	int bu=n/2,au=n-bu;
	int mi=n-(std::min(a,au)+std::min(b,bu));
	int ma=std::min(a,bu)+std::min(b,au);
	for(int i=mi;i<=ma;i+=2)ans[i]=1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<=a+b;i++)ans[i]=0;
		solve(a,b);
		solve(b,a);
		int cnt=0;
		for(int i=0;i<=a+b;i++)cnt+=ans[i];
		printf("%d\n",cnt);
		for(int i=0;i<=a+b;i++) if(ans[i])printf("%d ",i);
		puts("");
	}
}