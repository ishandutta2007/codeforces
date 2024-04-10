#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 2005;
char s[N][N];
bool valid[N][N];
int dp[N][N];
int x[N],y[N];
int lft[N][N], rgt[N][N];

int n, m, k;
void process_row(int i){
	for(int j = 1; j <= m; j++) lft[i][j] = (s[i][j] == 'X' ? 0 : lft[i][j - 1] + 1);
	for(int j = m; j >= 1; j--) rgt[i][j] = (s[i][j] == 'X' ? 0 : rgt[i][j + 1] + 1);
}

// is there some square of size sz containing some part of jth column?
int q1[N], q2[N], sz1, sz2;
bool possible_column(int j, int sz){
	if(sz > n || sz > m) return 0;
	int b1 = 1, e1 = 0, b2 = 1, e2 = 0;
	for(int i = 1; i <= n; i++){
		while(e1 >= b1 && lft[q1[e1]][j] >= lft[i][j]) e1--;
		q1[++e1] = i;
		while(b1 <= e1 && q1[b1] <= i - sz) b1++;

		while(e2 >= b2 && rgt[q2[e2]][j] >= rgt[i][j]) e2--;
		q2[++e2] = i;
		while(b2 <= e2 && q2[b2] <= i - sz) b2++;
		if(i >= sz && lft[q1[b1]][j] + rgt[q2[b2]][j] >= sz + 1) {
			return 1;
		}
	}
	return 0;
}
int val[N];
int main(){
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; i <= n; i++) process_row(i);
	for(int i = 1; i <= k; i++){
		sd(x[i]); sd(y[i]);
		s[x[i]][y[i]] = 'X';	
	}
	for(int i = 1; i <= n; i++) process_row(i);
	int ans = 0;
	for(int j = 1; j <= m; j++){
		while(possible_column(j, ans + 1)) ans++;
	}
	for(int i = k; i >= 1; i--){
		val[i] = ans;
		s[x[i]][y[i]] = '.';
		process_row(x[i]);
		while(possible_column(y[i], ans + 1)) ans++;
	}
	for(int i = 1; i <= k; i++) printf("%d\n", val[i]);
}