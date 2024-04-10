#include <bits/stdc++.h>
using namespace std;
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define ll long long
#define ld double
const int logN = 21, N = 1000005;
int ceillog[5 * N], v[N], c[N];
int RMQ[logN][N], rmq[logN][N];
inline int find_min(int i, int j){
	int k = ceillog[j-i+2] - 1;
    return min(rmq[k][i],rmq[k][j-(1<<k)+1]);	
}
inline int find_max(int i, int j){
	int k = ceillog[j-i+2] - 1;
    return max(RMQ[k][i],RMQ[k][j-(1<<k)+1]);	
}
int n = 0, k = 0;
inline int get_min(int i, int j){if(j < i || j > n) return 0; return min(find_max(i, j), find_min(i, j));}
int cnt = 0;
vector<int> V;
int main()
{
    for(k=1;(1<<k)<5*N;k++)
      for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
          ceillog[i] = k;
    for(int i = (1<<k);i<5*N;i++)        
        ceillog[i] = k+1;

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

    for(int i = n; i>= 1;i--){
		RMQ[0][i] = 100 * v[i];
		rmq[0][i] = c[i];
		int pw = 2, halfpw = 1;
		for(int j = 1; i + pw <= n + 1; j ++, pw += pw, halfpw += halfpw){
			RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][i + halfpw]);
			rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + halfpw]);
		}
	}
	for(int i = 1; i <= n; i++){
		int lo = i, hi = n;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			if(find_max(i, mid) > find_min(i, mid)) hi = mid;
			else lo = mid + 1; 
		}
		int val = max(get_min(i, lo), max(get_min(i, lo - 1), get_min(i, lo + 1)));
		V.push_back(val);
	}
	// print(V);
	sort(V.begin(), V.end());
	ld coeff = k / (ld) n, ans = 0;
	for(int i = 0; i <= n - k; i++){
		ans = ans + coeff * V[i];
		coeff *= n - i - k;
		coeff /= n - i - 1;
	}
	printf("%.10lf\n", ans);
}