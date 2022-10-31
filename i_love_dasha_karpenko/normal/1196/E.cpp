#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 10E9
const ll INF = 10E16;
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};

ll q,b,w;
vector<pp> ans;
int main() {
	schnell;
	cin >> q;
	forn(h, q) {
		cin >> b >> w;
		ans.clear();

		pp pos;
		ll turn = 0, vec = 0;
		if (b > w) {
			pos = pp{ 2,2 }; turn = 0;
		}
		else {
			pos = pp{ 2,3 };
			turn = 1;
		}
		pp start = pos;
		
		while (b > 0 && w > 0) {
			if (turn == 0) {
				ans.pb(pos);
				w--;
			}
			else {
				ans.pb(pos);
				b--;
			}
			turn ^= 1;
			if (vec == 0) {
				pos.sc++;
				if (pos.sc == MAXN - 1)vec = 1;
			}
			else if (vec == 1) {
				pos.fi++;
			}
		}
		
		if (b > 0) {
			if (turn==1) {
				ans.pb(pos);
				b--;
			}
			if (b > 0) {
				b--;
				ans.pb(pp{ start.fi, start.sc - 1 });
			}

			while (b > 0) {
				if (turn == 1)goto link;
				if (pos.fi == 3 && pos.sc == MAXN - 1) {
					ans.pb(pp{ pos.fi,pos.sc + 1 });
					b--;
				}
				else if (pos.fi == 2 && pos.sc == MAXN - 1) {
					ans.pb(pp{ pos.fi - 1,pos.sc });
					b--;
					if (b > 0) {
						ans.pb(pp{ pos.fi,pos.sc + 1 });
						b --;
					}
				}
				else {
					if (vec == 1) {
						ans.pb(pp{ pos.fi, pos.sc - 1 });
						b--;
						if (b > 0){
							ans.pb(pp{ pos.fi,pos.sc + 1 });
							b--;
						}
					}
					else {
						ans.pb(pp{ pos.fi - 1,pos.sc });
						b--;
						if (b > 0) {
							ans.pb(pp{ pos.fi + 1,pos.sc });
							b--;
						}
					}
				}
				link:
				turn ^= 1;
				if (pos == start)break;
				if (vec == 1) {
					pos.fi--;
					if (pos.fi == 2)vec = 0;
				}
				else if (vec == 0)pos.sc--;
			}
			if (b > 0) {
				cout << "NO" << endl;
				continue;
			}
			
		}
		///
		if (w > 0) {
			if (turn == 0) {
				ans.pb(pos);
				w--;
			}
			if (w > 0) {
				w--;
				ans.pb(pp{ start.fi, start.sc - 1 });
			}

			while (w > 0) {
				if (turn == 0)goto link1;
				if (pos.fi == 3 && pos.sc == MAXN - 1) {
					ans.pb(pp{ pos.fi,pos.sc + 1 });
					w--;
				}
				else if (pos.fi == 2 && pos.sc == MAXN - 1) {
					ans.pb(pp{ pos.fi - 1,pos.sc });
					w--;
					if (w > 0) {
						ans.pb(pp{ pos.fi,pos.sc + 1 });
						w--;
					}
				}
				else {
					if (vec == 1) {
						ans.pb(pp{ pos.fi, pos.sc - 1 });
						w--;
						if (w > 0) {
							ans.pb(pp{ pos.fi,pos.sc + 1 });
							w--;
						}
					}
					else {
						ans.pb(pp{ pos.fi - 1,pos.sc });
						w--;
						if (w > 0) {
							ans.pb(pp{ pos.fi + 1,pos.sc });
							w--;
						}
					}
				}
				link1:
				turn ^= 1;
				if (pos == start)break;
				if (vec == 1) {
					pos.fi--;
					if (pos.fi == 2)vec = 0;
				}
				else if (vec == 0)pos.sc--;
			}
			if (w > 0) {
				cout << "NO" << endl;
				continue;
			}

		}
		cout << "YES" << endl;
		for (pp to : ans) {
			cout << to.fi << ' ' << to.sc << endl;
		}
	}
	return 0;
}