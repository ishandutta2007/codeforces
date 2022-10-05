#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);
#define strs(args...) string args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	ints(t);
	while(t--) {
		int x = 1, y = 1;
		int pos[9][9] = {}, cnt = 63;
		for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) pos[i][j] = (i != 1 || j != 1);
		
		auto canmove = [&](int a, int b, int c, int d) {
			return (a != c || b != d) && (a == c || b == d || a - b == c - d || a + b == c + d);
		};
		
		auto kmove = [&](string s) {
			int npos[10][10] = {};
			int di = (s.find("Down") != string::npos) - (s.find("Up") != string::npos);
			int dj = (s.find("Right") != string::npos) - (s.find("Left") != string::npos);
			for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) {
				if(pos[i][j]) npos[i + di][j + dj] = 1;
			}
			cnt = 0;
			for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) {
				pos[i][j] = npos[i][j] && !(i == x && j == y) && !canmove(x, y, i, j);
				cnt += pos[i][j];
			}
		};
		
		auto finalize = [&](int kx, int ky) {
			while(true) {
				if(canmove(x, y, kx, ky)) {
					cout << kx << ' ' << ky << endl;
					strs(s);
					assert(s == "Done");
					return;
				}
				else {
					if(abs(kx - x) + abs(ky - y) == 3) {
						x += (kx > x) - (kx < x);
						y += (ky > y) - (ky < y);
					}
					else {
						x += (kx > x + 1) - (kx < x - 1);
						y += (ky > y + 1) - (ky < y - 1);
					}
					cout << x << ' ' << y << endl;
				}
				strs(s);
				if(s == "Done") return;
				kx += (s.find("Down") != string::npos) - (s.find("Up") != string::npos);
				ky += (s.find("Right") != string::npos) - (s.find("Left") != string::npos);
			}
		};
		
		cout << x << ' ' << y << endl;
		int done = 0;
		while(true) {
			strs(s);
			if(s == "Done") { done = 1; break; }
			else kmove(s);
			if(cnt == 1) break;
			
			int moved = 0;
			for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) {
				if(canmove(x, y, i, j) && pos[i][j]) {
					pos[i][j] = 0;
					cnt--;
					x = i; y = j;
					cout << x << ' ' << y << endl;
					moved = 1;
				}
			}
			if(!moved) {
				vpii cands;
				for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++) {
					if(canmove(x, y, i, j)) cands.emplace_back(i, j);
				}
				shuffle(all(cands), mt);
				pii p = cands[0];
				x = p.x; y = p.y;
				cout << x << ' ' << y << endl;
			}
		}
		if(done) continue;
		for(int i = 1; i <= 8; i++) for(int j = 1; j <= 8; j++)
			if(pos[i][j]) { finalize(i, j); break; }
	}
	
	return 0;
}