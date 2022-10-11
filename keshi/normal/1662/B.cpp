//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int cnt[26][3], ord[xn], td, MX, ted, b[3];
vector <int> khuba[3], bada[3], V[3];
string s[3];
vector <string> ans;

char intc(int x){
	return char('A' + x);
}
string F(int x, int y){
	string S = "";
	S += intc(x);
	S += intc(y);
	return S;
}
bool cmp(int i, int j){
	return SZ(V[i]) > SZ(V[j]);
}
int check(int x){
	int mx = 0, sum = 0;
	for (int i = 0; i < 3; ++ i){
		b[i] = SZ(s[i]) - x;
		b[i] = max(b[i], 0);
		mx = max(mx, b[i]);
		sum += b[i];
	}
	mx = max(mx, (sum + 1) / 2);
	return x + mx;
}

int main(){
	fast_io;

	for (int i = 0; i < 3; ++ i){
		string S;
		cin >> S;
		s[i] = S;
		for (char c : S)
			++ cnt[c - 'A'][i];
	}
	for (int i = 0; i < 26; ++ i){
		while (true){
			int mx = 0, sum = 0;
			for (int j = 0; j < 3; ++ j)
				sum += cnt[i][j], mx = max(mx, cnt[i][j]);
			if (sum == mx){
				for (int j = 0; j < 3; ++ j)
					for (int k = 0; k < cnt[i][j]; ++ k)
						bada[j].push_back(i);
				break;
			}
			int x, y;
			for (int j = 0; j < 3; ++ j)
				for (int k = 0; k < 3; ++ k)
					if (j != k && cnt[i][j] == mx && cnt[i][k])
						x = j, y = k;
			khuba[3 - x - y].push_back(i);
			++ td;
			-- cnt[i][x], -- cnt[i][y];
		}
	}
	MX = inf;
	for (int i = 0; i <= td; ++ i){
		int x = check(i);
		if (x < MX)
			MX = x, ted = i;
	}
	ted = td - ted;
	for (int i = 0; i < 3; ++ i){
		while (SZ(khuba[i]) && ted){
			-- ted;
			int x = khuba[i].back();
			khuba[i].pop_back();
			for (int j = 0; j < 3; ++ j)
				if (j != i)
					bada[j].push_back(x);
		}
	}
	for (int i = 0; i < 3; ++ i){
		for (int j = 0; j < SZ(khuba[i]); ++ j){
			if (j < SZ(bada[i]))
				ans.push_back(F(khuba[i][j], bada[i][j]));
			else
				ans.push_back(F(khuba[i][j], 0));
		}
		for (int j = SZ(khuba[i]); j < SZ(bada[i]); ++ j)
			V[i].push_back(bada[i][j]);
	}
	while (true){
		for (int i = 0; i < 3; ++ i)
			ord[i] = i;
		sort(ord, ord + 3, cmp);
		if (!SZ(V[ord[0]]))
			break;
		int x = ord[0], y = ord[1];
		if (!SZ(V[y]))
			V[y].push_back(0);
		ans.push_back(F(V[x].back(), V[y].back()));
		V[x].pop_back(), V[y].pop_back();
	}
	cout << SZ(ans) << endl;
	for (string x : ans)
		cout << x << endl;

	return 0;
}