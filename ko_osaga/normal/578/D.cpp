#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

int n, m;
char str[MAXN];
lint dp[MAXN][16];

lint f(int x, int msk){
	if(msk == 0) return 0;
	if(x == n) return (msk > 0);
	if(~dp[x][msk]) return dp[x][msk];
	lint ret = 0;
	for(int i=0; i<m; i++){
		int nmsk = 0;
		if(msk & 1){
			if(str[x+1] == i + 'a') nmsk |= 1;
			nmsk |= 8;
		}
		if(msk & 2){
			if(str[x] == i + 'a') nmsk |= 2;
			nmsk |= 4;
		}
		if(msk & 4){
			if(x && (str[x-1] == i + 'a')) nmsk |= 4;
		}
		if(msk & 8){
			if(str[x] == i + 'a') nmsk |= 8;
		}
		if(nmsk & 4) nmsk |= 8;
		if(nmsk & 2) nmsk |= 1;
		ret += f(x + 1, nmsk);
	}
	return dp[x][msk] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %s",&n,&m,str);
	cout << f(0, 3) - 1 << endl;
}