#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define ll long long
#define double long double
#define all(aaa) aaa.begin(), aaa.end()
using namespace std;


const int N = 15e4 + 5, T = 100, P = 1200, CP = N / P + 1;
int a[N], up[N], used[N], ct[N], b[N], t[CP][N];

int n, m, p, w = 0;

inline void handle(int l, int r, int p, int x) {
    for (int i = p * P; i < min(n, p * P + P); i++) {
        t[p][a[i]]--;
    }
	if (up[p]) {
		for (int i = p * P; i < min(n, p * P + P); i++) {
			a[i] = up[p];
		}
		up[p] = 0;
	}
	for (int i = l; i <= r; i++) {
		a[i] = x;
	}
	for (int i = p * P; i < min(n, p * P + P); i++) {
		t[p][a[i]]++;
	}
}

inline void work(int l, int r, int p) {
	if (up[p])
		ct[up[p]] += r - l + 1;
    else {
        for (int i = l; i <= r; i++) {
            if (used[a[i]] == w)
                ct[a[i]]++;
        }
	}
}

inline void upd(int l, int r, int x) {
	int lp = b[l],
		rp = b[r];
	for (int i = lp + 1; i < rp; i++) {
		up[i] = x;
	}
	if (lp == rp) {
		handle(l, r, lp, x);
	}
	else {
		handle(l, (lp + 1) * P - 1, lp, x);
		handle(rp * P, r, rp, x);
	}
}

inline int getVal(int x) {
	int p = b[x];
	if (up[p])
		return up[p];
	return a[x];
}

inline int getCt(int l, int r, vector<int> &cd) {
	int lp = b[l], rp = b[r], ans = 0;
	for (int i = lp + 1; i < rp; i++) {
	    for (int x : cd) {
	        if (up[i]) {
	            ct[x] += up[i] == x ? P : 0;
	        }
	        else {
	            ct[x] += t[i][x];
	        }
        }
	}
	if (lp == rp) {
		work(l, r, lp);
	}
	else {
		work(l, (lp + 1) * P - 1, lp);
		work(rp * P, r, rp);
	}

	return ans;
}

int getint() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

signed main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	n = getint();
	m = getint();
	p = getint();

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = i / P;
		t[b[i]][a[i]]++;
	}

	mt19937 rnd(time(0));

	while (m--) {
		int tp, x, y, z;
		tp = getint();
		x = getint();
		y = getint();
		x--, y--;

		if (tp == 1) {
			z = getint();
			upd(x, y, z);
		}
		else {
			vector<int> q, cd;
			w++;
			for (int i = 0; i < T; i++) {
				int g = rnd() % (y - x + 1) + x,
					val = getVal(g);
				if (used[val] == w)
					continue;
				used[val] = w;
				ct[val] = 0;
				cd.push_back(val);
			}

            getCt(x, y, cd);

			for (int val : cd) {
				if (ct[val] * 100 >= p * (y - x + 1)) {
					q.push_back(val);
                }
			}

			printf("%d", q.size());
			for (int i : q)
				printf(" %d", i);
			printf("\n");
		}
	}




	return 0;
}