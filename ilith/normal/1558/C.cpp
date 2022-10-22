#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
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
const int N=2060;
int n,t,a[N],p[N],fl;
vector<int>ans;
void rev(int r){reverse(a+1,a+r+1),ans.pbk(r);}
int find(int x){for(rgi i=1;i<=n;++i)if(a[i]==x)return i;}
signed main(){
	read(t);
	while(t--){
		read(n),fl=1,ans.clear();
		for(rgi i=1;i<=n;++i){
			read(a[i]);
			if((a[i]&1)^(i&1))fl=0;
		}
		if(!fl){
			puts("-1");
			continue;
		}
		for(rgi i=n;i>1;i-=2)rev(find(i)),rev(fl=find(i-1)-1),rev(fl+2),rev(3),rev(i);
		write(ans.size(),'\n');
		for(rgi k:ans)write(k,' ');
		puts("");
	}
	return 0;
}