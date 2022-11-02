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

#define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR2(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

using namespace std;

char in[120];
int n;
int best[2][80];

int main() {
	gets(in);
	scanf("%d", &n);
	int len = strlen(in);
	REP(j,2) REP(i,n+1) best[j][i] = -10000;
	best[1][0] = 0;
	REP(i,len) {
		FOR2(j,n,1){
			if (in[i]=='F') {
				int opt1, opt2;
				opt1 = best[1][j]+1;
				opt2 = best[0][j-1];
				best[1][j] = max(opt1,opt2);
				opt1 = best[0][j]-1;
				opt2 = best[1][j-1];
				best[0][j] = max(opt1,opt2);
			} else {
				int opt1, opt2;
				opt1 = best[0][j];
				opt2 = best[1][j-1]+1;
				int b1j = max(opt1,opt2);
				opt1 = best[1][j];
				opt2 = best[0][j-1]-1;
				best[0][j] = max(opt1,opt2);
				best[1][j] = b1j;
			}
		}
		if (in[i] == 'F') {best[1][0] = best[1][0]+1; best[0][0] = best[0][0]-1;}
		else {int b00 = best[0][0]; best[0][0] = best[1][0]; best[1][0] = b00;}
		/*REP(i,2)REP(j,n+1) printf("%d ", best[i][j]);
		printf("\n");*/
	}
	int p = n;
	int cand = -1;
	while (p >= 0) {
		cand = max(cand,max(best[1][p], best[0][p]));
		p -= 2;
	}
	REP(j,2) REP(i,n+1) best[j][i] = -10000;
	best[0][0] = 0;
	REP(i,len) {
		FOR2(j,n,1){
			if (in[i]=='F') {
				int opt1, opt2;
				opt1 = best[1][j]+1;
				opt2 = best[0][j-1];
				best[1][j] = max(opt1,opt2);
				opt1 = best[0][j]-1;
				opt2 = best[1][j-1];
				best[0][j] = max(opt1,opt2);
			} else {
				int opt1, opt2;
				opt1 = best[0][j];
				opt2 = best[1][j-1]+1;
				int b1j = max(opt1,opt2);
				opt1 = best[1][j];
				opt2 = best[0][j-1]-1;
				best[0][j] = max(opt1,opt2);
				best[1][j] = b1j;
			}
		}
		if (in[i] == 'F') {best[1][0] = best[1][0]+1; best[0][0] = best[0][0]-1;}
		else {int b00 = best[0][0]; best[0][0] = best[1][0]; best[1][0] = b00;}
		/*REP(i,2)REP(j,n+1) printf("%d ", best[i][j]);
		printf("\n");*/
	}
	p = n;
	int cand2 = -1;
	while (p >= 0) {
		cand2 = max(cand2,max(best[1][p], best[0][p]));
		p -= 2;
	}
	printf("%d\n", max(cand, cand2));
	return 0;
}