//https://codeforces.com/contest/1290/problem/B
#include<bits/stdc++.h>
using namespace std;
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t,c;
	inline void gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			c=s==t?EOF:*s++;
		}else c=*s++;
	}
	template<class IT>inline void gi(IT &x){
		x=0;gc();while(c<'0'||c>'9')gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);gc();}
	}
	char buf0[20];int a;
	template<class IT>inline void pi(IT x){
		if(x<0){putchar('-');x=-x;}
		do buf0[++a]=x%10+48;while(x/=10);
		while(a)putchar(buf0[a--]);
		putchar('\n');
	}
};
using io::gi;
using io::pi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll > pil;
typedef pair<ll ,int> pli;
typedef pair<ll ,ll > pll;
#define pque priority_queue
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
const int N=200005;
int f[N][26];
char c[N];
int main(){
	int n,q,i,j,k,t;
	scanf("%s%d",c+1,&q);
	n=strlen(c+1);
	rep(i,1,n){
		rep(j,0,25)f[i][j]=f[i-1][j];
		++f[i][c[i]-'a'];
	}
	while(q--){
		scanf("%d%d",&i,&k);--i;t=0;
		rep(j,0,25)if(f[i][j]!=f[k][j])++t;++i;
		if(t<=2&&c[i]==c[k]&&i!=k)puts("No");
		else puts("Yes");
	}
	return 0;
}