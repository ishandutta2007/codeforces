#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
int s[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		sort(s+1,s+n+1);
		bool flag=0;
		int j=1;
		for(int i=1;i<=n;i++){
			for(;j<=n&&s[j]-s[i]<k;j++);
			if(j<=n&&s[j]-s[i]==k)flag=1;
		}
		puts(flag?"YES":"NO");
	}
}