#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

string mask[10] = {"1110111", 
				   "0010010",
				   "1011101", 
				   "1011011", 
				   "0111010", 
				   "1101011", 
				   "1101111", 
				   "1010010", 
				   "1111111", 
				   "1111011"};

const ll N = 2011;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

ll n, k;

string a[N];

ll S[N][10];

bool was[N][N];

pill p[N][N];

ll dp[N][N];

bool rec(ll cur = 0, ll pal = k) {
	if(cur == n && pal == 0)
		return 1;
	if((pal < 0) ||  (cur == n && pal > 0)){
		return 0;
	}
	if(was[cur][pal])
		return dp[cur][pal];
	was[cur][pal] = 1;
	bool can = 1;
	for(int i = 0 ; i < 10 ; i++) {
		if(S[cur][i] == -1)
			continue;
		if(rec(cur + 1, pal - S[cur][i])) {
			p[cur][pal] = {pal - S[cur][i], i};
			dp[cur][pal] = 1;
		}
	}
	return dp[cur][pal];
}

int main() {
    speed;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 0; j < 10; j++){
			bool can = 1;
			ll cost = 0;
			for(int l = 0; l < 7; l++) {
				if(a[i][l] == '1' && mask[j][l] == '0')
					can = 0;
				cost += (a[i][l] == '0' && mask[j][l] == '1');
			}
			S[i][j] = cost;
			if(!can)
				S[i][j] = -1;
		}
	}
	if(!rec())
		cout << -1,ex;
	string ans;
	ll pal = k;
	for(int cur = 0 ; cur < n ; cur++){
		ans += to_string(p[cur][pal].s);
		pal = p[cur][pal].f;
	}
	cout << ans;
} 

/*
1
7 5
1 2 3 4 5 6 1
*/