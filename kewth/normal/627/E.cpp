/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 3030;
int pre[maxn], nxt[maxn];
int px[maxn], py[maxn];
int pp[maxn];
std::vector<int> line[maxn];
int ltmp[20], rtmp[20];

int main () {
	int n = read, m = read, N = read, K = read;
	for (int i = 1; i <= N; i ++) {
		read(px[i], py[i]);
		pp[i] = i;
		line[px[i]].push_back(i);
	}

	std::sort(pp + 1, pp + N + 1, [] (int a, int b) {
				return py[a] == py[b] ? px[a] < px[b] : py[a] < py[b];
			});

	ll ans = 0;

	auto calc = [m] (int i, int j) {
		if (!i or !j) return 0;
		/* debug(" calc %d %d\n", i, j); */
		return (py[i] - py[pre[i]]) * (m - py[j] + 1);
	};

	for (int u = 1; u <= n; u ++) {
		std::fill(pre, pre + N + 1, 0);
		std::fill(nxt, nxt + N + 1, 0);
		int las = 0;
		for (int i = 1; i <= N; i ++) {
			int id = pp[i];
			if (px[id] >= u) {
				pre[id] = las;
				if (las) nxt[las] = id;
				las = id;
			}
		}

		ll now = 0;
		int klas = las;
		for (int k = 1; k < K; k ++)
			klas = pre[klas];
		while (klas) {
			now += calc(klas, las);
			/* debug("%d %d %lld\n", klas, las, now); */
			klas = pre[klas];
			las = pre[las];
		}

		ans += now;
		for (int d = n; d >= u; d --) {
			/* debug("%d %d : %lld\n", u, d, now); */
			for (int id : line[d]) {
				for (int k = 1, x = pre[id]; k <= K; k ++)
					ltmp[k] = x, x = pre[x];
				ltmp[0] = rtmp[0] = id;
				for (int k = 1, x = nxt[id]; k <= K; k ++)
					rtmp[k] = x, x = nxt[x];

				now -= calc(id, rtmp[K - 1]);
				now -= calc(rtmp[1], rtmp[K]);
				for (int k = 1; k < K; k ++)
					now -= calc(ltmp[k], rtmp[K - 1 - k]);

				if (ltmp[1]) nxt[ltmp[1]] = rtmp[1];
				if (rtmp[1]) pre[rtmp[1]] = ltmp[1];
				pre[id] = nxt[id] = 0;

				now += calc(rtmp[1], rtmp[K]);
				for (int k = 1; k < K; k ++)
					now += calc(ltmp[k], rtmp[K - k]);
			}
			ans += now;
		}
		if (now) debug("ERROR %lld\n", now);
	}

	printf("%lld\n", ans);
}