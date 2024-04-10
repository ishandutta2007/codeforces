//Author: Hexun
//Date: 2019-04-29
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxm = 240000;
constexpr int maxn = 255;
char s[maxm], op[maxn], st[3][maxn];
int sz[3], f[maxn][maxn][maxn], nxt[26][maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q >> (s + 1);
	for(int i = n + 5; i >= 0; i -= 1)
		if(i > n) for(int j = 0; j < 26; j += 1) nxt[j][i] = n + 1;
		else for(int j = 0; j < 26; j += 1) if(j == s[i] - 'a') nxt[j][i] = i;
		else nxt[j][i] = nxt[j][i + 1];
	for(int x; q; q -= 1){
		cin >> op >> x;
		x -= 1;
		if(*op == '+'){
			cin >> op;
			st[x][sz[x] += 1] = *op;
			if(x == 0)
				for(int i = 0; i <= sz[1]; i += 1)
					for(int j = 0; j <= sz[2]; j += 1){
						f[sz[0]][i][j] = n + 1;
						f[sz[0]][i][j] = min(f[sz[0]][i][j], nxt[st[0][sz[0]] - 'a'][f[sz[0] - 1][i][j] + 1]);
						if(i) f[sz[0]][i][j] = min(f[sz[0]][i][j], nxt[st[1][i] - 'a'][f[sz[0]][i - 1][j] + 1]);
						if(j) f[sz[0]][i][j] = min(f[sz[0]][i][j], nxt[st[2][j] - 'a'][f[sz[0]][i][j - 1] + 1]);
					}
			if(x == 1)
				for(int i = 0; i <= sz[0]; i += 1)
					for(int j = 0; j <= sz[2]; j += 1){
						f[i][sz[1]][j] = n + 1;
						f[i][sz[1]][j] = min(f[i][sz[1]][j], nxt[st[1][sz[1]] - 'a'][f[i][sz[1] - 1][j] + 1]);
						if(i) f[i][sz[1]][j] = min(f[i][sz[1]][j], nxt[st[0][i] - 'a'][f[i - 1][sz[1]][j] + 1]);
						if(j) f[i][sz[1]][j] = min(f[i][sz[1]][j], nxt[st[2][j] - 'a'][f[i][sz[1]][j - 1] + 1]);
					}
			if(x == 2)
				for(int i = 0; i <= sz[0]; i += 1)
					for(int j = 0; j <= sz[1]; j += 1){
						f[i][j][sz[2]] = n + 1;
						f[i][j][sz[2]] = min(f[i][j][sz[2]], nxt[st[2][sz[2]] - 'a'][f[i][j][sz[2] - 1] + 1]);
						if(i) f[i][j][sz[2]] = min(f[i][j][sz[2]], nxt[st[0][i] - 'a'][f[i - 1][j][sz[2]] + 1]);
						if(j) f[i][j][sz[2]] = min(f[i][j][sz[2]], nxt[st[1][j] - 'a'][f[i][j - 1][sz[2]] + 1]);
					} 
		}
		else{
			sz[x] -= 1; 
		}
		cout << (f[sz[0]][sz[1]][sz[2]] == n + 1 ? "NO\n" : "YES\n");
		//for(int i = 0; i <= sz[0]; i += 1)
		//	for(int j = 0; j <= sz[1]; j += 1)
		//		for(int k = 0; k <= sz[2]; k += 1){
		//			cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
		//		}
	}
	return 0;
}