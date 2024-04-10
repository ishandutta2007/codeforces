#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef vector<string> vs;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.F >> P.S;
	return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

int d[55][55][55][55], bcnt[55][55][55][55];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vs a(n);
	cin >> a;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			for(int k = i; k <= n; k ++){
				for(int l = j; l <= n; l ++){
					bcnt[i][j][k][l] = bcnt[i][j][k - 1][l] + bcnt[i][j][k][l - 1] - bcnt[i][j][k - 1][l - 1] + (a[k - 1][l - 1] == '#');
				}
			}
		}
	}
	for(int k = 0; k < n; k ++){
		for(int l = 0; l < n; l ++){
			for(int i = 1; i + k <= n; i ++){
				for(int j = 1; j + l <= n; j ++){
					int ei = i + k, ej = j + l;
					d[i][j][ei][ej] = max(k, l) + 1;
					for(int r = i; r <= ei; r ++){
						if(!bcnt[r][j][r][ej]){
							d[i][j][ei][ej] = min(d[i][j][ei][ej], d[i][j][r - 1][ej] + d[r + 1][j][ei][ej]);
						}
					}
					for(int c = j; c <= ej; c ++){
						if(!bcnt[i][c][ei][c]){
							d[i][j][ei][ej] = min(d[i][j][ei][ej], d[i][j][ei][c - 1] + d[i][c + 1][ei][ej]);
						}
					}
				}
			}
		}
	}
	cout << d[1][1][n][n];
	return 0;
}