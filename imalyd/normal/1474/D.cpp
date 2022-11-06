#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=(a);i<=(b);++i)
#define per(i,a,b) for(i=(a);i>=(b);--i)
#define REP(i,a,b) for(i=(a);i< (b);++i)
#define PER(i,a,b) for(i=(a);i> (b);--i)
typedef long long ll;
#define ERR(...) fprintf(stderr,__VA_ARGS__);

inline void ac();
int main(){
	int t;scanf("%d",&t);while(t--)ac();
	return 0;
}
const int MAXN=200005;
int A[MAXN];ll S[MAXN];bool L[MAXN],R[MAXN];
inline void ac(){
	int n,i;
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&A[i]);S[i]=S[i-1]+((i&1)?A[i]:(-A[i]));}
	L[0]=true;
	rep(i,1,n)L[i]=L[i-1]&&((i&1)?(S[i  ]>=0ll ):(S[i  ]<=0ll ));
	R[n]=true;
	per(i,n,1)R[i-1]=R[i]&&((i&1)?(S[i-1]<=S[n]):(S[i-1]>=S[n]));
	if(!S[n]&&L[n]){puts("YES");return;}
	//rep(i,0,n)ERR("%lld ",S[i]);ERR("S\n");
	//rep(i,0,n)ERR("%d ",L[i]);ERR("L\n");
	//rep(i,0,n)ERR("%d ",R[i]);ERR("R\n");
	REP(i,1,n)if(L[i-1]&&R[i+1]){
		if(i&1){
			if(S[n]==2*(A[i]-A[i+1])&&S[i-1]+A[i+1]>=0){puts("YES");return;}
		}else{
			if(S[n]==2*(A[i+1]-A[i])&&S[i-1]-A[i+1]<=0){puts("YES");return;}
		}
	}
	puts("NO");
}