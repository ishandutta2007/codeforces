#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

char h[] = "br";

int n;
pii pt[200005];
bool Ex[200005];

vector < pii > E[1000005];
char out[200005];

vector < int > GetPath(int id){
	vector < int > R;
	for (int i = 0; i < (int)E[id].size(); ++i){
		pii e = E[id][i];
		if (Ex[e.y]){
			swap(E[id][i], E[id].back());
			E[id].pop_back();
			--i;
			continue;
		}
		Ex[e.y] = true;
		R.pb(e.y);
		id = e.x;
		i = -1;
	} return R;
}

int main(){
	scanf("%d", &n);
	FOR(0, n, i) scanf("%d%d", &pt[i].x, &pt[i].y), pt[i].y += 500000;
	FOR(0, n, i) E[pt[i].x].pb({pt[i].y, i}), E[pt[i].y].pb({pt[i].x, i});
	
	FOR(0, 1000005, i)
		while (true){
			vector < int > R1 = GetPath(i), R2 = GetPath(i);
			if (R1.size() == 0) break;
			int tmp = 0;
			for (auto x : R1){
				out[x] = h[tmp];
				tmp ^= 1;
			}
			tmp = 1;
			for (auto x : R2){
				out[x] = h[tmp];
				tmp ^= 1;
			}
		}
	
	out[n] = '\0';
	printf("%s\n", out);
	
	return 0;
}