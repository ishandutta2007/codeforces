#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int K;
    while(cin >> K){
        int n[3];
        int t[3];
        REP(i, 3) cin >> n[i];
        REP(i, 3) cin >> t[i];
        int cnt[3] = {};
        REP(i, 3) cnt[i] = n[i];
        const int MAX_T = 1 << 14;
        int add[3][MAX_T] = {};
        for(int time = 0; ; time++){
            // REP(i, 3) if(time % t[i] == 0) cnt[i] = n[i];
            REP(i, 3) cnt[i] += add[i][time & (MAX_T - 1)];
            REP(i, 3) add[i][time & (MAX_T - 1)] = 0;
            int use = min(cnt[0], min(cnt[1], cnt[2]));
            if(use == 0) continue;
            if(K <= use) {
                cout << time + t[0] + t[1] + t[2] << endl;
                break;
            }
            K -= use;
            REP(i, 3) cnt[i] -= use;
            REP(i, 3) add[i][(time + t[i]) & (MAX_T - 1)] += use;
        }
    }
    return 0;
}