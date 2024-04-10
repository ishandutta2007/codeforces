/*program by mangoyang*/
#pragma GCC optimize("Ofast", "inline")
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef unsigned long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int ch = 0, f = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
const int N = 100005;
char a[N], b[N];
int n, m;
int main(){
	int T; read(T);
	while(T--){
		read(n), read(m);
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		int flag = 0;
		for(int i = 1; i < m; i++)
			if(a[n-i+1] != b[m-i+1]){
				puts("NO");
				flag = 1;
				break;
			}
		if(flag) continue;
		for(int i = m; i <= n; i++)
			if(a[n-i+1] == b[1]){
				puts("YES");
				flag = 1;
				break;
				
			}
		if(flag) continue;
		puts("NO");
	}
	return 0;
}