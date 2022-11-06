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
const int MAXN=100005;
char S[MAXN];
inline void ac(){
	int n,i,a,l=9;
	scanf("%d%s",&n,S);
	REP(i,0,n){
		a=S[i]^'0';
		if(a+1==l){putchar('0');l=a;}
		else{putchar('1');l=a+1;}
	}
	putchar('\n');
}