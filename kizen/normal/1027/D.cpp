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

const int NS = (int)2e5+4;
int N, val[NS], way[NS], chk[NS], chkVal;

int main(){
    scanf("%d", &N);
    REP1(i, N) scanf("%d", val+i);
    REP1(i, N) scanf("%d", way+i);

    int ans = 0;
    REP1(i, N) if(!chk[i]){
        ++chkVal;
        int pos = i;
        while(!chk[pos]){
            chk[pos] = chkVal, pos = way[pos];
        }
        if(chk[pos]==chkVal){
            int Plus = INF;
            for(int j=way[pos];j!=pos;j=way[j]) Plus = min(Plus, val[j]);
            Plus = min(Plus, val[pos]);
            ans += Plus;
        }
    }
    printf("%d", ans);

    return 0;
}