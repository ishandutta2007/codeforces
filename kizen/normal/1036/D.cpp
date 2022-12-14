#include <bits/stdc++.h>

using namespace std;

const int INF = 2*(1e9)+4;
const long long IINF = (1e18)+4;
#define REP(i, N) for(int (i)=0;(i)<(N);++(i))
#define REP1(i, N) for(int (i)=1;(i)<=(N);++(i))
#define REPD(i, N) for(int (i)=(N)-1;(i)>=0;--(i))
#define REP1D(i, N) for(int (i)=(N);(i)>=1;--(i))
#define FOR(i, s, e) for(int (i)=(s);(i)<=(e);++(i))
#define FORD(i, s, e) for(int (i)=(s);(i)>=(e);--(i))
#define FORN(i, s, e, x) for(int (i)=(s);(i)<=(e);(i)+=(x))
#define FORND(i, s, e, x) for(int (i)=(s);(i)>=(e);(i)-=(x))
#define MP make_pair

typedef long long LL;
const int NS = (int)3e5+4;
LL N, M, A[NS], B[NS];
map < LL, LL > mp;

int main(){
    scanf("%d", &N);
    REP1(i, N) scanf("%lld", A+i), A[i] += A[i-1];
    scanf("%d", &M);
    REP1(i, M) scanf("%lld", B+i), B[i] += B[i-1], mp[B[i]] = 1;
    int cnt = 0;
    REP1(i, N) cnt += mp[A[i]];
    printf("%d", A[N]==B[M]? cnt:-1);

    return 0;
}