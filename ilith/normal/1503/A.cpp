#include<bits/stdc++.h>
#define rgi register int
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
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
const int N=200010;
int t,n;
char ans[N];
char s[N];
signed main(){
	read(t);
	while(t--){
		read(n),scanf("%s",s+1);
		if(s[1]!='1'||s[n]!='1'){
			puts("NO");
			continue;
		}
		ans[1]='(',ans[n]=')';
		int rs1=0,rs0=0,cnt0=0;
		for(rgi i=2;i<n;++i){
			if(s[i]=='1'){
				if(rs1)rs1=0,ans[i]=')';
				else rs1=1,ans[i]='(';
			}
			else{
				++cnt0;
				if(rs0)rs0=0,ans[i]=')';
				else rs0=1,ans[i]='(';
			}
		}
		if(cnt0&1){
			puts("NO");
			continue;
		}
		puts("YES");
		for(rgi i=1;i<=n;++i)write(ans[i]);
		write('\n');
		for(rgi i=1;i<=n;++i){
			if(s[i]=='1')write(ans[i]);
			else write(ans[i]=='('?')':'(');
		}
		write('\n');
	}
	return 0;
}