/*program by mangoyang*/
#pragma GCC optimize("Ofast", "inline")
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int ch = 0, f = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define int ll
const int N = 1000005;
int a[N];
int n, m;
signed main(){
	int T; read(T);
	while(T--){
		read(n), read(m);
		ll S1 = -1, S2 = -1, cntS1 = 0, cntS2 = 0, idS1 = 0, idS2 = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++) read(a[j]);
			ll S = 0;
			for(int j = 1; j <= m; j++) 
				a[j] += a[j-1], S += a[j];
			if(i == 1){
				S1 = S, cntS1++, idS1 = 1;
				continue;
			}
			if(S == S1) cntS1++, idS1 = i;
			else{
				if(S2 == -1) S2 = S;
				cntS2++, idS2 = i;
			}
		}
		if(cntS1 == 1) swap(S1, S2), swap(idS1, idS2);
		printf("%lld %lld\n", idS2, S1 - S2);
	}
	return 0;
}