#include <bits/stdc++.h>
#define maxn 2005

using namespace std;

int n, K;
char s[10];
vector<pair<int, int> > v[maxn];
bool f[maxn][maxn];
int ans[maxn];

char a[10][10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main(){
	scanf("%d%d", &n, &K);
	for(int i = 1;i <= n;i++){
		scanf("%s", s);
		for(int j = 0;j <= 9;j++){
			int x = 0;
			for(int k = 0;k < 7;k++){
				if(a[j][k] == '1' && s[k] == '0') x++;
				else if(a[j][k] == '0' && s[k] == '1') break;
				if(k == 6) v[i].push_back({j, x});
			}
		}
	}
	f[n + 1][0] = true;
	for(int i = n;i;i--){
		for(int j = 0;j < v[i].size();j++){
			for(int k = 0;k <= K;k++){
				if(k - v[i][j].second >= 0) f[i][k] |= f[i + 1][k - v[i][j].second];
				//printf("%d %d %d--\n", i, k, f[i][k]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		int x = -1, y = K;
		for(int j = 0;j < v[i].size();j++){
			//printf("%d %d %d--\n", j, v[i][j].first, v[i][j].second);
			if(K - v[i][j].second >= 0 && f[i + 1][K - v[i][j].second] && v[i][j].first > x){
				x = v[i][j].first, y = K - v[i][j].second;
			} 
		}
		if(x == -1) return printf("-1"), 0;
		ans[i] = x, K = y;
	}
	for(int i = 1;i <= n;i++) printf("%d", ans[i]);
}