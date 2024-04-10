#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vi> board(n + 2, vi(m + 2));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> board[i][j];
		}
	}
	vector<vi> left(n + 2, vi(m + 2)), right(n + 2, vi(m + 2, m + 1)), up(n + 2, vi(m + 2)), down(n + 2, vi(m + 2, n + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			left[i][j] = board[i][j] ? left[i][j - 1] : j;
		}
		for(int j = m; j >= 1; j --){
			right[i][j] = board[i][j] ? right[i][j + 1] : j;
		}
	}
	for(int j = 1; j <= m; j ++){
		for(int i = 1; i <= n; i ++){
			up[i][j] = board[i][j] ? up[i - 1][j] : i;
		}
		for(int i = n; i >= 1; i --){
			down[i][j] = board[i][j] ? down[i + 1][j] : i;
		}
	}
	while(q --){
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1){
			board[x][y] = !board[x][y];
			if(!board[x][y]){
				left[x][y] = right[x][y] = y;
				up[x][y] = down[x][y] = x;
				for(int i = y + 1; board[x][i]; i ++){
					left[x][i] = y;
				}
				for(int i = y - 1; board[x][i]; i --){
					right[x][i] = y;
				}
				for(int i = x + 1; board[i][y]; i ++){
					up[i][y] = x;
				}
				for(int i = x - 1; board[i][y]; i --){
					down[i][y] = x;
				}
			}
			else{
				for(int i = y; board[x][i]; i ++){
					left[x][i] = left[x][y - 1];
				}
				for(int i = y; board[x][i]; i --){
					right[x][i] = right[x][y + 1];
				}
				for(int i = x; board[i][y]; i ++){
					up[i][y] = up[x - 1][y];
				}
				for(int i = x; board[i][y]; i --){
					down[i][y] = down[x + 1][y];
				}
			}
		}
		else{
			vector<vi> d(4);
			for(int i = 0; i <= m + 1; i ++){
				d[0].push_back(x - up[x][i]);
				d[1].push_back(down[x][i] - x);
			}
			for(int i = 0; i <= n + 1; i ++){
				d[2].push_back(y - left[i][y]);
				d[3].push_back(right[i][y] - y);
			}
			d[0][0] = d[1][0] = d[2][0] = d[3][0] = d[0].back() = d[1].back() = d[2].back() = d[3].back() = 0;
			int res = 0;
			vi X{x, x, y, y};
			for(auto &data: d){
				int s = data.size() - 2;
				deque<int> ql(1, 0);
				vi resl(s + 2);
				for(int i = 1; i <= s; i ++){
					while(ql.back() && data[ql.back()] >= data[i]){
						ql.pop_back();
					}
					resl[i] = ql.back() + 1;
					ql.push_back(i);
				}
				deque<int> qr(1, s + 1);
				vi resr(s + 2);
				for(int i = s; i >= 1; i --){
					while(qr.back() != s + 1 && data[qr.back()] >= data[i]){
						qr.pop_back();
					}
					resr[i] = qr.back() - 1;
					qr.push_back(i);
				}
				int k = X.back();
				X.pop_back();
				for(int i = 1; i <= s; i ++){
					if(resl[i] <= k && resr[i] >= k){
						res = max(res, data[i] * (resr[i] - resl[i] + 1));
					}
				}
			}
			cout << res << "\n";
		}
	}
	return 0;
}
/*
5 5 100000
1 0 0 0 0
1 1 1 0 1
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0
1 3 2
2 3 2
*/