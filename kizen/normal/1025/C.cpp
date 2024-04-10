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

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> s;
    s += s;
    int last = 0, ans = 0;
    REP1(i, (int)s.size()-1){
        if(s[i]==s[i-1]) last = i;
        ans = max(ans, i-last+1);
    }
    cout << min(ans, (int)s.size()/2);

    return 0;
}