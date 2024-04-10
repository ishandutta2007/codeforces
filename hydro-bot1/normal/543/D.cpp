// =============================================
// !
// Author: 
// Blog: https://www.cnblogs.com/SasebonoShigure
// =============================================

#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const LL Mod = 1e9 + 7;
const int Maxn = 2e5 + 10;

int n, u;
LL f[Maxn], g[Maxn];

int Head[Maxn], Total = 1;
int Next[Maxn << 2], To[Maxn << 2];

inline void Addedge (const int u, const int v) {
	To[++ Total] = v, Next[Total] = Head[u], Head[u] = Total;
	To[++ Total] = u, Next[Total] = Head[v], Head[v] = Total;
	return ;
}

inline void Search (const int Index, const int Pre) {
	f[Index] = 1;
	
	for (int i = Head[Index]; i; i = Next[i] ) {
		if (To[i] == Pre ) {
			continue ;
		}
		
		Search (To[i], Index);
		f[Index] = f[Index] * (f[To[i]] + 1) % Mod;
	}
	
	return ;
}

inline void Solve (const int Index, const int From) {
	int Count = -1, t = 0;
	vector <LL> Pre, Suf;
	g[Index] = 1;
	
	for (int i = Head[Index]; i; i = Next[i] ) {
		g[Index] = g[Index] * (f[To[i]] + 1) % Mod;
		
		if (To[i] ^ From ) {
			Pre.push_back (f[To[i]] + 1);
			Suf.push_back (f[To[i]] + 1);
			++ Count;
		}
	}
	
	for (int i = 1; i <= Count; ++ i ) {
		Pre[i] = Pre[i - 1] * Pre[i] % Mod;
		Suf[Count - i] = Suf[Count - i + 1] * Suf[Count - i] % Mod;
	}
	
	for (int i = Head[Index]; i; i = Next[i] ) {
		if (To[i] == From ) {
			continue ;
		}
		
		f[Index] = f[From] + 1;
		
		if (t ) {
			f[Index] = f[Index] * Pre[t - 1] % Mod;
		}
		
		if (t < Count ) {
			f[Index] = f[Index] * Suf[t + 1] % Mod;
		}
		
		Solve (To[i], Index);
		++ t;
	}
	
	return ;
}

signed main () {
	scanf ("%d", &n);
	
	for (int i = 2; i <= n; ++ i ) {
		scanf ("%d", &u), Addedge (u, i);
	}
	
	Search (1, 0), Solve (1, 0);
	
	for (int i = 1; i <= n; ++ i ) {
		printf ("%lld ", g[i]);
	}
	
	return 0;
}