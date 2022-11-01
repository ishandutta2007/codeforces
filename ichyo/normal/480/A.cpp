#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    typedef pair<int, int> P;
    int N;
    cin >> N;
    vector<P> vp(N);
    REP(i, N) cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end());
    int last = 0;
    for(int i = 0; i < N; i++) {
        if(last <= vp[i].second) {
            last = vp[i].second;
        } else {
            assert(last <= vp[i].first);
            last = vp[i].first;
        }
    }
    cout << last << endl;
    return 0;
}