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

#define MAXL 100100
char in[MAXL];
#define MAXK 15
int K;
char pr[30];

int main() {
	gets(in);
	scanf("%d\n", &K);
	char buff[5];
	REP(i,30) pr[i] = 30;
	REP(i,K) {
		gets(buff);
		pr[buff[0]-'a'] = buff[1] - 'a';
		pr[buff[1]-'a'] = buff[0] - 'a';
	}
	int i = 0;
	int res = 0;
	while (in[i]) {
		int c1 = in[i]-'a';
		int c2 = pr[c1];
		if (c2 == 30) {
			++i;
			continue;
		}
		int begin = i;
		while (in[i+1]-'a' == c1 || in[i+1]-'a' == c2) ++i;
		int end = i;
		int c1c = 0, c2c = 0;
		FOR(j,begin,end) {
			if (in[j]-'a' == c1) ++c1c;
			else ++c2c;
		}
		res += min(c1c, c2c);
		i = end+1;
	}
	printf("%d\n", res);
	return 0;
}