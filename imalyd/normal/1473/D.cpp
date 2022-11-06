#include<bits/stdc++.h>
using namespace std;
#define ERR(...) fprintf(stderr,__VA_ARGS__);
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
typedef long long ll;
const int MAXN=200005;
struct seq{
	int l,r,c;
	inline seq operator+(const seq &s)const{
		return (seq){min(l,c+s.l),max(r,c+s.r),c+s.c};
	}
	inline int size()const{
		return r-l+1;
	}
}P[MAXN],S[MAXN];
const seq empty=(seq){0,0,0};
const seq add=(seq){0,1,1};
const seq sub=(seq){-1,0,-1};
char C[MAXN];
inline void ac(){
	int n,q,i,j;
	scanf("%d%d%s",&n,&q,C+1);
	rep(i,1,n)P[i]=P[i-1]+(C[i]=='+'?add:sub);
	S[n+1]=empty;
	per(i,n,1)S[i]=(C[i]=='+'?add:sub)+S[i+1];
	while(q--){
		scanf("%d%d",&i,&j);
		printf("%d\n",(P[i-1]+S[j+1]).size());
	}
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)ac();
	return 0;
}