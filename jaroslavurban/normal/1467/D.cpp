#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5050,m=1e9+7;
int dp[N][N];
int sm[N];
int a[N];

// spam inline infront of everything xd
const int MAXSIZE = 1 << 18 | 1;
char buf[MAXSIZE], *p1, *p2;

inline int Gc() {
	return p1 == p2 &&
		(p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2)? EOF: *p1++;
}
template<typename T> inline void read(T& x) {
	x = 0; int f = 0, ch = Gc();
	while (!isdigit(ch)) f |= ch == '-', ch = Gc();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = Gc();
	if (f) x = -x;
}

inline void write(register int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10^48);
}


main(){
	int n,k,q;
	read(n);read(k);read(q);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=0;i<n;++i)dp[0][i]=1;
	for(int i=1;i<=k;++i)
		for(int j=0;j<n;++j)
			dp[i][j]=((j?dp[i-1][j-1]:0)+(j<n-1?dp[i-1][j+1]:0))%m;
	for(int i=0;i<=k;++i)
		for(int j=0;j<n;++j)
			sm[j]=(sm[j]+dp[i][j]*ll(dp[k-i][j]))%m;
	int tot=0;
	for(int i=0;i<n;++i)tot=(tot+ll(a[i])*sm[i])%m;
	while(q--){
		int idx,x;read(idx);read(x);--idx;
		tot=(tot+sm[idx]*ll(x-a[idx])%m+m)%m;
		a[idx]=x;
		write(tot);putchar('\n');
	}
}