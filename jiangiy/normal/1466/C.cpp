#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n;
char s[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		for(int i=2;i<=n;i++){
			if(s[i]==s[i-1]||s[i]==s[i-2]){
				for(int j=0;j<26;j++) if(j+97!=s[i-1]&&j+97!=s[i-2]&&j+97!=s[i+1]&&j+97!=s[i+2]){
					s[i]=j+97;
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}