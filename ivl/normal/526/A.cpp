#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long

using namespace std;

void YES(){printf("yes\n"); exit(0);}

int n;
char in[105];

bool check(int i, int j, int cnt = 4){
	if (i >= n) return false;
	if (in[i] == '.') return false;
	if (cnt == 0) return true;
	return check(i + j, j, cnt - 1);
}

int main(){
	scanf("%d%s", &n, in);
	FOR(0, n, i) FOR(1, n, j) if (check(i, j)) YES();
	printf("no\n");
	return 0;
}