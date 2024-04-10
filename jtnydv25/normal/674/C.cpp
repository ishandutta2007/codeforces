#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define Long double
const int N = 2e5 + 10;
const ld eps = 1e-9;
const ld inf = 1e18;
ld dp[55][N], S[N], H[N], F[N];
int t[N];

struct Line {
    Long a, b, get(Long x) { return a * x + b; }
};

struct ConvexHull {
    int size;
    Line hull[N];

    ConvexHull() {
        size = 0;
    }

    bool is_bad(int curr, int prev, int next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }

    void add_line(Long a, Long b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    Long query(Long x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }
};
// dp[j][i] =  - max_k ( (H[i]) * S[k] - (dp[j - 1][k] + S[k] * H[k] - F[k]) ) + F[i]
// Evaluate max( S[k] * x - (dp[j - 1][k] + S[k] * H[k] - F[k]) ) at x = H[i]
int main(){
	int n, K;
	sd(n); sd(K);
	for(int i = 1; i <= n; i++){
		sd(t[i]);
		S[i] = S[i - 1] + t[i];
		H[i] = H[i - 1] + 1./t[i];
		F[i] = F[i - 1] + S[i] / t[i];
		dp[1][i] = F[i];
	}

	for(int j = 2; j <= K; j++){
		ConvexHull Hull;
		for(int i = 1; i <= n; i++){
			if(i == 1){
				dp[j][i] = inf;
			}
			else{
				dp[j][i] = F[i] - Hull.query(H[i]);
			}
			ld m = S[i], c = -dp[j - 1][i] + F[i] - S[i] * H[i];
			Hull.add_line(m, c);
		}
	}
	printf("%.8lf\n", dp[K][n]);
}