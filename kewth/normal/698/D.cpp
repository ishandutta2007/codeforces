#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

struct Dot { int x, y; };
struct Vector {
	int x, y;
	inline ll len() { return 1ll * x * x + 1ll * y * y; }
};
inline Vector operator - (Dot a, Dot b) {
	return {a.x - b.x, a.y - b.y};
}
inline Dot operator + (Dot a, Vector b) {
	return {a.x + b.x, a.y + b.y};
}
inline bool operator < (Dot a, Dot b) { // for std::set
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
inline int from(Vector a) {
	return a.y > 0 or (a.y == 0 and a.x < 0);
}
inline bool cmp(Vector a, Vector b) { // weak
	if(from(a) != from(b)) return from(a) < from(b);
	return 1ll * a.y * b.x < 1ll * b.y * a.x;
}
inline bool operator < (Vector a, Vector b) { // strong
	if(from(a) != from(b))
		return from(a) < from(b);
	return 1ll * a.y * b.x == 1ll * b.y * a.x ?
		a.len() < b.len() : cmp(a, b);
}

const int maxn = 10, maxm = 1010;
Vector ang[maxn][maxm];
Dot shut[maxn], monster[maxm];

int n = read, m = read;
bool fuck(std::set<Dot> Mon, std::set<Dot> Die, std::vector<int> Shu) {
	if(Mon.size() == Die.size()) return 1;
	if(Shu.empty()) return 0;

	auto it = Mon.begin();
	while(Die.count(*it))
		++ it;
	Dot mo = *it;
	Die.insert(mo);

	for(auto it = Shu.begin(); it != Shu.end(); ++ it) {
		int i = *it;
		Dot s = shut[i];
		std::set<Dot> nMon = Mon;
		std::vector<int> nShu = Shu;
		nShu.erase(std::find(nShu.begin(), nShu.end(), i));

		int l = int(std::lower_bound(ang[i] + 1,
					ang[i] + m + 1, mo - s, cmp) - ang[i]);
		int r = int(std::lower_bound(ang[i] + 1,
					ang[i] + m + 1, mo - s) - ang[i] - 1);

		for(int j = l; j <= r and nMon.size() <=
				nShu.size() + Die.size(); j ++) {
			Dot now = s + ang[i][j];
			nMon.insert(now);
		}
		if(nMon.size() <= nShu.size() + Die.size() and fuck(nMon, Die, nShu))
			return 1;
	}
	return 0;
}

int main() {
	for(int i = 1; i <= n; i ++) {
		shut[i].x = read;
		shut[i].y = read;
	}
	for(int i = 1; i <= m; i ++) {
		monster[i].x = read;
		monster[i].y = read;
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++)
			ang[i][j] = monster[j] - shut[i];
		std::sort(ang[i] + 1, ang[i] + m + 1);
	}

	std::vector<int> Shu;
	for(int i = 1; i <= n; i ++)
		Shu.push_back(i);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		std::set<Dot> Mon, Die;
		Mon.insert(monster[i]);
		ans += fuck(Mon, Die, Shu);
	}
	printf("%d\n", ans);
}