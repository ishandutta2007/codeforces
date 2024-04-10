#include <cstdio>
#include <cstring>
#include <algorithm>

char s[100001];
long long cnt[26][26],tot[26],n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)
			cnt[j][s[i]-'a']+=tot[j];
		++tot[s[i]-'a'];
	}
	long long ans=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++)
			ans=std::max(ans,cnt[i][j]);
		ans=std::max(ans,tot[i]);
	}
	printf("%lld\n",ans);
}