#include <algorithm>
#include <cstdio>
using namespace std;
const int mo = 1e9 + 7;
const int N = 1e4 + 10;
int n, pos, posx, dp[N][27][2]; //0 -> or; 1 -> ; 2 ->  
char s[3][N]; //O;
bool emp[N];
void upd(int &x, const int &y) {
	(x += y) >= mo ? x -= mo : 0;
}
int bit(int S, int x) {
	if(x == 0) return S % 3;
	if(x == 1) return S / 3 % 3;
	return S / 9;
}
bool match(int S1, int S2) {
	for(int i = 0; i < 3; i ++) {
		if((bit(S2, i) == 1) + (bit(S1, i) == 2) == 1) return 0;
	}
	return 1;
}
bool valid(int S, int x) {
	int cnt = 0, tag[3] = {0};
	for(int i = 0; i < 3; i ++) if(s[i][x] == '.') {
		if(!bit(S, i)) cnt ++, tag[i] = 1;
	} else if(bit(S, i)) return 0;
	return cnt % 2 == 0 && !(tag[0] && tag[2]);
}
bool _rowl(int S, int x) { return x == pos && bit(S, posx) == 1; }
bool _rowr(int S, int x) { return x == pos && bit(S, posx) == 2; }
bool _col(int S, int x) {
	return emp[x] && x == pos && posx != 1 && (bit(S, 0) | bit(S, 1) | bit(S, 2)) == 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 3; i ++) scanf("%s", &s[i][1]);
	for(int i = 0; i < 3; i ++) for(int j = 1; j <= n; j ++)
		if(s[i][j] == 'O') { posx = i; pos = j; break ; }
	for(int i = 1; i <= n; i ++) emp[i] = s[0][i] != 'X' && s[1][i] != 'X' && s[2][i] != 'X';
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < 27; j ++) {
			for(int v = 0; v < 2; v ++) if(dp[i - 1][j][v]) {
//				printf("dp[%d][%d][%d] = %d\n", i - 1, j, v, dp[i - 1][j][v]);
				for(int S = 0; S < 27; S ++) if(match(j, S) && valid(S, i)) {
				 	int u = v;
				 	if(!u) u = _rowl(j, i) || _col(S, i) || _rowr(S, i - 1);
					upd(dp[i][S][u], dp[i - 1][j][v]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 27; i ++) {
		if((bit(i, 0) | bit(i, 1) | bit(i, 2)) < 2) {
			upd(ans, dp[n][i][1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}