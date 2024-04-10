#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 10;
const int MAXM = 3e5 + 10;

int a[MAXN][MAXN], vis[MAXN][MAXN];
char s[MAXN];

typedef pair<int, int>PII;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int f[MAXM], num[MAXM];
int Miao[MAXM];
int tot, n, K, cnt, ans;

void Calc(int x, int y){
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	int sum = 0, rm = 0;
	if (x > 0){
		for(int i = 0; i < K; i++){
			if (a[x-1][y+i]){
				if (Miao[vis[x-1][y+i]] == 0){
					sum += f[vis[x-1][y+i]];
					Miao[vis[x-1][y+i]] = 1;
					Q.push(vis[x-1][y+i]);
					rm += num[vis[x-1][y+i]];
				}
			}
		}
	}
	if (x + K < n){
		for(int i = 0; i < K; i++){
			if (a[x+K][y+i]){
				if (Miao[vis[x+K][y+i]] == 0){
					sum += f[vis[x+K][y+i]];
					Miao[vis[x+K][y+i]] = 1;
					Q.push(vis[x+K][y+i]);
					rm += num[vis[x+K][y+i]];
				}
			}
		}
	}
	if (y > 0){
		for(int i = 0; i < K; i++){
			if (a[x+i][y-1]){
				if (Miao[vis[x+i][y-1]] == 0){
					sum += f[vis[x+i][y-1]];
					Miao[vis[x+i][y-1]] = 1;
					Q.push(vis[x+i][y-1]);
					rm += num[vis[x+i][y-1]];
				}
			}
		}
	}
	if (y + K < n){
		for(int i = 0; i < K; i++){
			if (a[x+i][y+K]){
				if (Miao[vis[x+i][y+K]] == 0){
					sum += f[vis[x+i][y+K]];
					Miao[vis[x+i][y+K]] = 1;
					Q.push(vis[x+i][y+K]);
					rm += num[vis[x+i][y+K]];
				}
			}
		}
	}
	ans = max(ans, sum + K * K - rm);
//	cout<<x<<' '<<y<<' '<<sum<<' '<<rm<<' '<<tot<<' '<<ans<<endl;
	while(!Q.empty()){
		int z = Q.front(); Q.pop();
		Miao[z] = 0;
	}
}

int main(){
	cin>>n>>K;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			vis[i][j] = 0;
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < n; j++)
			a[i][j] = (s[j] == '.');
	}
	ans = 0;
	cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (a[i][j] && !vis[i][j]){
				cnt++;
				f[cnt] = 1;
				queue<PII> Q;
				while(!Q.empty()) Q.pop();
				Q.push(PII(i, j));
				vis[i][j] = cnt;
				while(!Q.empty()){
					PII Nico = Q.front();
					Q.pop();
					int x = Nico.first, y = Nico.second;
					for(int k = 0; k < 4; k++){
						if (0 <= dx[k] + x && dx[k] + x < n && dy[k] + y >= 0 && dy[k] + y < n)
							if (!vis[x + dx[k]][y + dy[k]] && a[x + dx[k]][y + dy[k]]){
								vis[x + dx[k]][y + dy[k]] = cnt;
								f[cnt]++;
								Q.push(PII(x + dx[k], y + dy[k]));
							}
					}
				}
				ans = max(ans, f[cnt]);
			}
	/*		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<vis[i][j]<<' ';
		cout<<endl;
	}
		*/	
	tot = 0;
	for(int i = 1; i <= cnt; i++)
		num[i] = 0, Miao[i] = 0;
	for(int i = 0; i < K; i++){
		for(int j = 0; j < K; j++)
			if (a[i][j]){
				tot++;
				num[vis[i][j]]++;
			}
	}
	for(int i = 0; i <= n - K; i++){
		if (i & 1){
			for(int j = n - K; j >= 0; j--){
				Calc(i, j);
				if (j != 0){
					for(int k = 0; k < K; k++)
						if (a[i+k][j+K-1]){
							tot--;
							num[vis[i+k][j+K-1]]--;
						}
					for(int k = 0; k < K; k++)
						if (a[i+k][j-1]){
							tot++;
							num[vis[i+k][j-1]]++;
						}
				}
				else{
					for(int k = 0; k < K; k++)
						if (a[i][j+k]){
							tot--;
							num[vis[i][j+k]]--;
						}
					for(int k = 0; k < K; k++)
						if (a[i+K][j+k]){
							tot++;
							num[vis[i+K][j+k]]++;
						}
				}
			}
		}
		else{
			for(int j = 0; j <= n - K; j++){
				Calc(i, j);
				if (j != n - K){
					for(int k = 0; k < K; k++)
						if (a[i+k][j]){
							tot--;
							num[vis[i+k][j]]--;
						}
					for(int k = 0; k < K; k++)
						if (a[i+k][j+K]){
							tot++;
							num[vis[i+k][j+K]]++;
						}
				}
				else{
					for(int k = 0; k < K; k++)
						if (a[i][j+k]){
							tot--;
							num[vis[i][j+k]]--;
						}
					for(int k = 0; k < K; k++)
						if (a[i+K][j+k]){
							tot++;
							num[vis[i+K][j+k]]++;
						}
				}
			}
		}
	}	
	cout<<ans<<endl;	
	return 0;
}