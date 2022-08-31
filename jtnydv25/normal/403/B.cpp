#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 5005;
int A[N], B[N];
int n, m;
int getMin(int C[]){
	int p = 1e9;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		p = min(C[i], p);
		ans += C[i] - p;
	}
	return ans;
}

int arr[N];

set<int> st;
map<int, int> factors[N];
int k1, k2;
vector<int> vec[105];
int mn[105][N];
int curr[105];

int main(){
	sd(n); sd(m);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		sd(A[i]);
	}
	for(int j = 1; j <= m; j++){
		sd(B[j]);
		st.insert(B[j]);
		memset(arr, 0, sizeof arr);
	}
	for(int i = 1; i <= n; i++){
		int x = A[i];
		for(int j = 2; j * j <= x; j++){
			int k = 0;
			while(x % j == 0) k++, x /= j;
			if(k){
				if(st.count(j)) ans-=k;
				else ans+=k;
				factors[i][j] = k;
			}
		}
		if(x != 1){
			if(st.count(x)) ans--;
			else ans++;
			factors[i][x] = 1;
		}
	}

	for(int i = 1; i <= m; i++){
		if(factors[1][B[i]]){
			k1++;
			mn[k1][0] = 1e9;
			vec[k1].resize(n + 1);
			for(int j = 1; j <= n; j++){
				vec[k1][j] = factors[j][B[i]];
				mn[k1][j] = min(mn[k1][j - 1], vec[k1][j]);
			}
		}
	}

	for(auto it : factors[1]){
		int p = it.F, k = it.S;
		if(!st.count(p)){
			k2++;
			mn[k1 + k2][0] = 1e9;
			vec[k1 + k2].resize(n + 1);
			for(int j = 1; j <= n; j++){
				vec[k1 + k2][j] = factors[j][p];
				mn[k1 + k2][j] = min(mn[k1 + k2][j - 1], vec[k1 + k2][j]);
			}
		}
	}
	for(int i = n; i >= 1; i--){
		int profit = 0;
		for(int j = 1; j <= k1; j++){
			profit += mn[j][i] - curr[j];
		}
		for(int j = k1 + 1; j <= k1 + k2; j++){
			profit -= mn[j][i] - curr[j];
		}

		if(profit > 0){
			ans += profit * i;
			for(int j = 1; j <= k1 + k2; j++)
				curr[j] = mn[j][i];
		}
	}

	printf("%d\n", ans);
}