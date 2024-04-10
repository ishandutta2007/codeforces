#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,s[55];
		scanf("%d",&n);
		std::set<int>f;
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		for(int i=1;i<=n;i++) for(int j=1;j<=i-1;j++)f.insert(s[i]-s[j]);
		printf("%d\n",f.size());
	}
}