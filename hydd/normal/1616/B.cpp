#include<bits/stdc++.h>
using namespace std;
int T,n; char s[110000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); int ans=1;
		scanf("%s",s+1); char ch=s[1];
		for (int i=2;i<=n;i++){
			if (s[i-1]!=s[i]) ch=s[i-1];
			if (s[i]<ch) ans=i;
			else break;
		}
		for (int i=1;i<=ans;i++) putchar(s[i]);
		for (int i=ans;i>=1;i--) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}