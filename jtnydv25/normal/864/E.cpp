#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
const int N = 105;

int dp[N][2005], t[N], d[N];
int lst1[N][2005], lst2[N][2005], p[N];
int perm[N];

bool cmp(int i, int j){
	return d[i] < d[j];
}

const int INF = 1e9;
int main(){
	int  n;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 2005; j++)
			dp[i][j] = -INF;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(t[i]); sd(d[i]); sd(p[i]);
		perm[i] = i;
	}
	d[0] = INF;
	sort(perm + 1, perm + n + 1, cmp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		int ind = perm[i];
		int D = d[ind];
		for(int j = 0; j < i; j++){
			for(int lastt = 0; lastt < D - t[ind] && lastt < d[perm[j]]; lastt++){
				if(p[ind] + dp[j][lastt] >= dp[i][lastt + t[ind]]){
					dp[i][lastt + t[ind]] = p[ind] + dp[j][lastt];
					lst1[i][lastt + t[ind]] = j;
					lst2[i][lastt + t[ind]] = lastt;
				}
			}
		}
	}

	int mx = 0;
	vector<int> vec;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2005; j++){
			if(dp[i][j] > mx){
				vec.clear();
				mx = dp[i][j];
				int x = i, y = j;
				while(dp[x][y] > 0){
					vec.push_back(perm[x]);
					int new_x = lst1[x][y];
					int new_y = lst2[x][y];
					x = new_x, y = new_y;
				}
			}
		}
	}


	printf("%d\n", mx);
	// sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	printf("%d\n", (int)vec.size());
	for(int x : vec) printf("%d ", x);
}