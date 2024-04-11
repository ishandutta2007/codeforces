#include <bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i != r; i++)
#define fi0(x) memset((x), 0, sizeof(x))
#define ins insert

const int QSZ = 5e5 + 5;
const int TSZ = 5e6 + 666;

int cnt[TSZ];
int nxt[TSZ][5];
int ptr = 1;
int q[2][QSZ];
bool was[TSZ];

void create(int i){
	F(k, 0, 5)nxt[i][k] = -1;
	cnt[i] = 0;
}

void add(string & s){
	int v = 0;
	I(c, s){
		if(nxt[v][c - 'a'] == -1){create(ptr); nxt[v][c - 'a'] = ptr++;}
		v = nxt[v][c - 'a'];
	}
	cnt[v]++;
}

int n, m;
string s;

int main(){
	//freopen("t.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	create(0);
	fi0(was);
	cin >> n >> m;
	F(i, 0, n){
		cin >> s;
		add(s);
	}
	F(i, 0, m){
		cin >> s;
		int tc = 0;
		int cp = 1;
		q[tc][0] = 0;
		I(c, s){
			if(c != '?'){
				int dcp = 0;
				F(j, 0, cp){
					int u = nxt[q[tc][j]][c - 'a'];
					if(u != -1)q[1 - tc][dcp++] = u;
				}
				cp = dcp; tc = 1 - tc;
			}
			else{
				int dcp = 0;
				F(j, 0, cp){
					F(k, 0, 5)if(nxt[q[tc][j]][k] != -1)q[1 - tc][dcp++] = nxt[q[tc][j]][k];
					q[1 - tc][dcp++] = q[tc][j];
				}
				cp = dcp; tc = 1 - tc;
			}
		}
		int ans = 0;
		F(j, 0, cp)if(cnt[q[tc][j]] != 0)was[q[tc][j]] = true;
		F(j, 0, cp)if(cnt[q[tc][j]] != 0){
			if(was[q[tc][j]]){ans += cnt[q[tc][j]]; was[q[tc][j]] = false;}
		}
		cout << ans << '\n';
	}
	return 0;
}