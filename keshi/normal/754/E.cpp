//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 410;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int sig = 26;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

int n, m, r, c;
string s[maxn], t[maxn];
bitset<maxn> b[maxn][sig], bt;
bool bad[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> t[i];
		for(int j = 0; j < c; j++){
			if(t[i][j] == '?') continue;
			for(int o = 0; o < sig; o++){
				if(int(t[i][j] - 'a') != o) b[j][o][i] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int jj = j;
			bt.reset();
			for(int o = 0; o < c; o++){
				bt |= b[o][s[i][jj] - 'a'];
				jj++;
				if(jj == m) jj = 0;
			}
			int ii = i;
			for(int o = 0; o < r; o++){
				if(bt[o]) bad[ii][j] = 1;
				ii--;
				if(ii == -1) ii = n - 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << (!bad[i][j]);
		}
		cout << "\n";
	}
	
	return 0;
}