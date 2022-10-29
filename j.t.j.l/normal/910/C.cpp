#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

struct pt{
	ll cnt;
	int let, isled;
};

vector<pt> f;

int vis[MAXN];
char s[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	int m = 'j' - 'a' + 1;
	f.resize(m);
	for (int i = 0; i < m; i++) {
		f[i].cnt = 0ll;
		f[i].let = i;
		f[i].isled = 0;
	}
	for (int j = 1; j <= n; j++){
		scanf("%s", s + 1);
		int nn = strlen(s + 1);
		ll now = 1;
		for (int i = nn; i >= 1; i--){
			f[s[i] - 'a'].cnt += now;
			now *= 10;
		}
		f[s[1]-'a'].isled = 1;
	}
	sort(f.begin(), f.end(), [](const pt & a, const pt & b){
		if (a.cnt == b.cnt)
			return a.isled < b.isled;
		else return a.cnt > b.cnt;
	});
	for (int i = 0; i < 10; i++) vis[i] = 0;
	ll ans = 0;
	for (int j = 0; j < m; j++){
		int k = -1;
		for (int i = f[j].isled; i < 10; i++)
			if (!vis[i]){
				k = i;
				break;
			}
		vis[k] = 1;
		ans += f[j].cnt * k;
	}
	printf("%lld\n", ans);
}

void printans(){

}

int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}