// Hydro submission #62c561a3c3a9fda5622968cc@1657102755736
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define meow(args...) fprintf(stderr,args)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?-x:x;
}
int T,n;
int sum[1000001][2];
char s[500001];
inline void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1,now=0;i<=n;i++){
		sum[now+n][s[i]-'0']++;
		if(s[i]=='0') now--;else now++;
	}
	for(int i=1,x=0;i<=n;i++){
		if(sum[x+n][0]&&sum[x-1+n][1]) sum[x+n][0]--,x--,putchar('0');
		else if(sum[x+n][1]) sum[x+n][1]--,x++,putchar('1');
		else sum[x+n][0]--,x--,putchar('0');
	}
	puts("");
}
signed main(){
	T=read();while(T--) solve();
	return 0;
}