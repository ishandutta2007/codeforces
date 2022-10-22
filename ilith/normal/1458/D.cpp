#include<bits/stdc++.h>
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=500010;
int t,now,n;
char s[N];
int sum[N];
map<int,int>mp[2];
void chg(int x){
	write(x);
	--mp[x][now];
	now+=(x?1:-1);
}
signed main(){
	read(t);
	while(t--){
		mp[0].clear(),mp[1].clear(),now=0;
		scanf("%s",s+1),n=strlen(s+1);
		for(rgi i=1;i<=n;++i){
			int num=s[i]-'0';
			++mp[num][sum[i-1]];
			sum[i]=sum[i-1]+(num?1:-1);
		}
		while(n--){
			if(mp[0][now]&&mp[1][now-1])chg(0);
			else chg(!!mp[1][now]);
		}
		puts("");
	}
	return 0;
}