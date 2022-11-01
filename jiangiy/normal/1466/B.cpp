#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,s[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		std::sort(s+1,s+n+1);
		int ans=0,lst=-1;
		for(int i=1;i<=n;i++){
			if(lst<s[i]){
				lst=s[i];
				ans++;
			}
			else if(lst==s[i]){
				lst=s[i]+1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}