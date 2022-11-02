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

int N, K;
int sti[2000];
int pei[2000];
int stp[2000];
int pep[2000];
int stc = 0;
int pec = 0;

int srt[2000];

bool ilt(int i1, int i2) { return stp[i1] > stp[i2]; }

int main() {
	scanf("%d%d", &N, &K);
	REP(i,N) {
		int p, t;
		scanf("%d%d", &p, &t);
		if (t == 1) {
			sti[stc] = i;
			stp[stc] = p;
			++stc;
		} else {
			pei[pec] = i;
			pep[pec] = p;
			++pec;
		}
	}
	if (K > stc) {
		ll pr2 = 0;
		REP(i,stc) pr2 += stp[i];
		REP(i,pec) pr2 += pep[i]*2;
		printf("%I64d", pr2/2);
		if (pr2%2) puts(".5");
		else puts(".0");
		REP(i,stc) {
			printf("1 %d\n", sti[i]+1);
		}
		REP(i,K-stc-1) {
			printf("1 %d\n", pei[i]+1);
		}
		printf("%d ", pec-K+stc+1);
		FOR(i,K-stc-1,pec-1) {
			printf(i==pec-1?"%d\n":"%d ", pei[i]+1);
		}
	} else {
		REP(i,stc) srt[i] = i;
		sort(srt,srt+stc,ilt);
		ll pr2 = 0;
		REP(i,K-1) {
			pr2 += stp[srt[i]];
		}
		int minp = stp[srt[K]];
		FOR(i,K-1,stc-1) {
			pr2 += stp[srt[i]]*2;
			minp = min(stp[srt[i]], minp);
		}
		REP(i,pec) {
			pr2 += pep[i]*2;
			minp = min(pep[i], minp);
		}
		pr2 -= minp;
		printf("%I64d", pr2/2);
		if (pr2%2) puts(".5");
		else puts(".0");
		REP(i,K-1) {
			printf("1 %d\n", sti[srt[i]]+1);
		}
		printf("%d ", pec+stc-K+1);
		FOR(i,K-1,stc-1) {
			printf((i == stc-1 && !pec) ? "%d\n" : "%d ", sti[srt[i]]+1);
		}
		REP(i,pec) {
			printf(i == pec-1?"%d\n":"%d ", pei[i]+1);
		}
	}
	return 0;
}