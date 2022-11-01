#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef pair<int, int> P;

int main(){
    int W, H;
    while(cin >> W >> H){
        vector<P> pset;
        REP(dy, 2) REP(dx, 2) {
            if(dx <= W && dy <= H)
                pset.push_back(P(dx, dy));
        }
        REP(dy, 2) REP(dx, 2) {
            if(dx <= W && H - dy >= 0)
                pset.push_back(P(dx, H - dy));
        }
        REP(dy, 2) REP(dx, 2) {
            if(W - dx >= 0 && dy <= H)
                pset.push_back(P(W - dx, dy));
        }
        REP(dy, 2) REP(dx, 2) {
            if(W - dx >= 0 && H - dy >= 0)
                pset.push_back(P(W - dx, H - dy));
        }
        sort(pset.begin(), pset.end());
        pset.erase(unique(pset.begin(), pset.end()), pset.end());
        vector<pair<double, vector<P>>> ans;

        for(int comb = (1 << 4) - 1; comb < (1 << pset.size());){
            vector<P> ps;
            REP(i, pset.size()) if(comb >> i & 1) {
                ps.push_back(pset[i]);
            }
            sort(ps.begin(), ps.end());
            do{
                double len = 0;
                REP(i, 3) {
                    len += hypot(ps[i].first - ps[i + 1].first, ps[i].second - ps[i + 1].second);
                }
                ans.push_back(make_pair(len, ps));
            }while(next_permutation(ps.begin(), ps.end()));

            int x = comb & -comb, y = comb + x;
            comb = ((comb & ~y) / x >> 1) | y;
        }
        sort(ans.begin(), ans.end());
        vector<P> ps = ans.back().second;
        REP(i, 4) {
            cout << ps[i].first << " " << ps[i].second << endl;
        }
    }
    return 0;
}