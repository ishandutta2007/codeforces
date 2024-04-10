#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define ll long long


const int maxn = 1 << 9;
const int maxk = 16;
const ll q[2] = {239, 1000000007};

char S[maxk][2][2];
int n, m, pw[maxk], K;
ll P[maxn][2], h[maxk];
string p[maxk][maxk][maxn], s[maxn];

ll hs[maxn][maxn];
//set<ll> st[16];
vector<ll> v[16];
void precalc() {
	P[0][0] = P[0][1] = 1;
	for (int i = 1; i < maxn; i++) 
		P[i][0] = P[i-1][0] * q[0], P[i][1] = P[i-1][1] * q[1];

	for (int o = 0; o < 16; o++) {
		if (o & 1)
			S[o][0][0] = '*';
		else 
			S[o][0][0] = '.';
		if (o & 2)
			S[o][0][1] = '*';
		else 
			S[o][0][1] = '.';
		if (o & 4)
			S[o][1][0] = '*';
		else 
			S[o][1][0] = '.';
		if (o & 8)
			S[o][1][1] = '*';
		else 
			S[o][1][1] = '.';
	}

	pw[0] = 1;
	K = 0;
	while (pw[K] <= 500) {
		pw[K+1] = pw[K]*2;
		K++;
	}

	for (int it = 0; it < 16; it++) {
		p[it][0][0] = ".";
		for (int it2 = 0; it2 < K-1; it2++) {
			for (int i = 0; i < pw[it2+1]; i++)
				p[it][it2+1][0] += '.';
			for (int i = 1; i < pw[it2+1]; i++)
				p[it][it2+1][i] = p[it][it2+1][0];
			for (int i = 0; i < pw[it2]; i++) 
				for (int j = 0; j < pw[it2]; j++) {
					if (p[it][it2][i][j] == '*') {
						p[it][it2+1][i*2][j*2] = p[it][it2+1][i*2+1][j*2] = p[it][it2+1][i*2][j*2+1] = p[it][it2+1][i*2+1][j*2+1] = '*';
					} else {
						if (S[it][0][0] == '*')
							p[it][it2+1][i*2][j*2] = '*';
						if (S[it][0][1] == '*')
							p[it][it2+1][i*2][j*2+1] = '*';
						if (S[it][1][0] == '*')
							p[it][it2+1][i*2+1][j*2] = '*';
						if (S[it][1][1] == '*')
							p[it][it2+1][i*2+1][j*2+1] = '*';
					}
				}
		}
		for (int it2 = 0; it2 < K; it2++) {
			ll hash = 0;
			for (int i = 0; i < pw[it2]; i++)
				for (int j = 0; j < pw[it2]; j++)
					hash += (p[it][it2][i][j] == '*') * P[i][0] * P[j][1];
			v[it2].push_back(hash);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	precalc();
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> s[i];

	hs[0][0] = s[0][0] == '*';
	for (int i = 1; i < n; i++)
		hs[i][0] = hs[i-1][0] + (s[i][0] == '*') * P[i][0];
	for (int j = 1; j < m; j++)
		hs[0][j] = hs[0][j-1] + (s[0][j] == '*') * P[j][1];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			hs[i][j] = hs[i-1][j] + hs[i][j-1] - hs[i-1][j-1] + (s[i][j] == '*') * P[i][0] * P[j][1];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int it = 2; i+pw[it]<=n && j+pw[it]<=m; it++) {
				long long hash1 = hs[i+pw[it]-1][j+pw[it]-1];
				hash1 -= i ? hs[i-1][j+pw[it]-1] : 0;
				hash1 -= j ? hs[i+pw[it]-1][j-1] : 0;
				hash1 += i && j ? hs[i-1][j-1] : 0;
				bool res = 0;
				for (int x = 0; x < 16; x++) {
					ll hash = v[it][x];
					hash *= P[i][0] * P[j][1];
					res |= hash == hash1;
				}
				if (res)
					ans = ans;
				ans += res;
			}
		}
	}

	cout << ans;
	return 0;
}