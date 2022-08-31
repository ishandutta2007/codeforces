#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N;
int asLen;
string as[100010];

int main() {
	int i;
	string cmd, option, name;
	
	for (; cin >> N; ) {
		asLen = 0;
		for (; N--; ) {
			cin >> cmd;
			if (cmd == "cd") {
				cin >> option;
				if (option[0] == '/') {
					asLen = 0;
					option = option.substr(1);
				}
				for (uint j = 0; j < option.size(); ++j) {
					if (option[j] == '/') {
						option[j] = ' ';
					}
				}
				istringstream iss(option);
				for (; iss >> name; ) {
					if (name == "..") {
						assert(asLen > 0);
						--asLen;
					} else {
						as[asLen++] = name;
					}
				}
			} else if (cmd == "pwd") {
				for (i = 0; i < asLen; ++i) {
					printf("/%s", as[i].c_str());
				}
				puts("/");
			} else {
				assert(0);
			}
		}
	}
	
	return 0;
}