// Hydro submission #62f0b774403a5e414e088639@1659942773258
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, nxt[N], v[N];
char s[N];
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;++i) {
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) ++j;
		nxt[i]=j;
		if(i!=n) v[j]=1;
	}
	int ans=nxt[n], fg=0;
	while(ans) {
		if(v[ans]) { fg=1; break; }
		ans=nxt[ans];
	}
	if(!fg) { puts("Just a legend"); return 0; }
	for(int i=1;i<=ans;++i) printf("%c",s[i]);
	puts("");
}