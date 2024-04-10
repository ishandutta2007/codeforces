
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#define ull unsigned ll
const int N = 200050;
const int JZP = 998244353;
ull ch[26][N], A[55], B[55], Ba = 13331, bas[N];
int m, n;
char s[N];
ll A2[55], B2[55];
ll jzp[26][N], jbas[N];
void work(int l, int r, ull *A, ll *A2) {
	for (int i = 0;i < 26; i++) 
		A[i] = ch[i][r] - ch[i][l-1] * bas[r - l + 1];
	for (int i = 0;i < 26; i++) 
		A2[i] = (jzp[i][r] + (JZP - jzp[i][l-1]) * jbas[r - l + 1]) % JZP;
	sort(A, A + 26), sort(A2, A2 + 26);
}


int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(m);
	scanf ("%s", s + 1);
	bas[0] = 1, jbas[0] = 1;
	for (int i = 1;i <= n; i++) 
		bas[i] = bas[i-1] * Ba, jbas[i] = jbas[i-1] * Ba % JZP;
	for (int i = 0;i < 26; i++) 
		for (int j = 1;j <= n; j++) 
			ch[i][j] = ch[i][j-1] * Ba + (s[j] == i + 'a'),
			jzp[i][j] = (jzp[i][j-1] * Ba + (s[j] == i + 'a')) % JZP;
	while (m--) {
		int x, y, z; read(x), read(y), read(z);
		work(x, z + x - 1, A, A2), work(y, z + y - 1, B, B2);
		bool fl = 0;
		for (int i = 0;i < 26; i++) 
			if (A2[i] != B2[i] || A[i] != B[i]) { fl = 1; break; }
		puts(fl ? "NO" : "YES");
	}
	return 0;
}

/*

100 1
bababccabaacacaabbabaabaacbcabbaabaababcccbbcaacabbaabaccaabbcabbbcaaabacaacbabcaccccacaabbacabbbbba
100 18 1

*/