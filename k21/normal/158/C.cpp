#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

int N;
char cmd[10];
char par[300];
string path = "/";

int main() {
	scanf("%d", &N);
	REP(ci,N) {
		scanf("%s", cmd);
		if (cmd[0] == 'c') {
			scanf("%s", par);
			int i = 0;
			if (par[0] == '/') {
				path = "/";
				++i;
			}
			while (par[i]) {
				int j = i;
				while (par[j] != '/' && par[j] != 0) ++j;
				if (j-i == 2 && par[i] == '.' && par[i+1] == '.') {
					int k = path.length()-2;
					while (path[k] != '/') --k;
					path = path.substr(0, k+1);
				} else {
					path += string(par+i, j-i) + "/";
				}
				if (!par[j]) i = j;
				else i = j+1;
			}
		} else {
			cout << path << '\n';
		}
	}
	return 0;
}