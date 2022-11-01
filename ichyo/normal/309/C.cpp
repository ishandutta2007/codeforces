#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        const int MAXL = 32;
        int cnt[MAXL] = {};
        vector<int> a(n);
        REP(i, n) scanf("%d", &a[i]);
        REP(i, m) {
            int t;
            scanf("%d", &t);
            cnt[t] ++;
        }

        int p = 0;
        int ans = 0;
        for(int b = 0; b < MAXL; b++) {
            REP(i, n) if(a[i] >> b & 1) {
                int rest = (1 << b);
                while(true) {
                    while((1 << p) <= rest && cnt[p] == 0) {
                        p++;
                    }

                    if((1 << p) > rest) break;

                    int use = min(cnt[p], rest / (1 << p));
                    cnt[p] -= use;
                    ans += use;
                    rest -= use * (1 << p);
                }
                a[i] -= (1 << b) - rest;
            }
        }
        cout << ans << endl;
    }
    return 0;
}