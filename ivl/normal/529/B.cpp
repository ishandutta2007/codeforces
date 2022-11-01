#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), __for = (b); c < __for; ++c)
#define REP(n) for (int __rep = 0, __for = (n); __rep < __for; ++__rep)

using namespace std;

const int oo = 1000000000;

int n;
int w[1005], h[1005];

long long solve(int maxH){
	long long W = 0;
	int lie = 0;
	vector < int > V;
	FOR(0,n,i){
		int x = w[i], y = h[i];
		if (x > maxH && y > maxH) return oo;
		if (x > maxH) W += x;
		if (y > maxH) W += y, ++lie;
		if (x <= maxH && y <= maxH){
			W += x;
			V.push_back(y - x);
		}
	}
	if (lie > n/2) return oo;
	sort(V.begin(), V.end());
	FOR(0,min((int)V.size(),n/2-lie),i){
		if (V[i] >= 0) break;
		W +=V[i];
	}
	return W;
}

int main(){
	scanf("%d", &n);
	FOR(0,n,i) scanf("%d%d", w + i, h + i);
	long long R = oo;
	FOR(0,n,i) R = min(R, solve(w[i]) * w[i]);
	FOR(0,n,i) R = min(R, solve(h[i]) * h[i]);
	printf("%d\n", (int)R);
	return 0;
}