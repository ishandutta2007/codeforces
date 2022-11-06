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
		for(int i = 1; i <= m; i++) read(a[i]);
		sort(a + 1, a + m + 1);
		vector<int> vec;
		for(int i = 2; i <= m; i++)
			vec.push_back(a[i] - a[i-1] - 1);
		vec.push_back(a[1] - 1 + n - a[m]);	
		sort(vec.begin(), vec.end());
		int ans = 0, t = 0;
		for(int i = (int) vec.size() - 1; i >= 0; i--){
			int x = vec[i] - t * 2;
			if(x <= 0) break;
			if(x <= 2) ans++, t++;
			else ans += x - 1, t += 2;
		}
		
		printf("%lld\n", n - ans);
	}
	return 0;
}