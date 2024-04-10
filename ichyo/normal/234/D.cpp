#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int m, k;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> m >> k;
    vector<bool> fav(m + 1, false);
    REP(i, k){
        int t; cin >> t;
        fav[t] = true;
    }
    int n;
    cin >> n;
    vector<int> maxv(n), minv(n);
    REP(i, n){
        string s; cin >> s;
        int L;
        cin >> L;
        int cnt = 0;
        int zeros = 0;
        REP(_, L){
            int t; cin >> t;
            if(fav[t]) cnt++;
            if(t == 0) zeros++;
        }
        int rpep = m - (L - zeros);
        int rfav = k - cnt;
        int rnof = rpep - rfav;
        //printf("restpeople: %d fav: %d nofav: %d zeros: %d \n", rpep, rfav, rnof, zeros);
        minv[i] = cnt + (rnof >= zeros ? 0 : zeros - rnof);
        maxv[i] = min(cnt + zeros, k);
        //printf("minv[%d] = %d maxv[%d] = %d\n", i, minv[i], i, maxv[i]);
    }
    REP(i, n){
        bool b1 = true; // surely be <-> minv[i] >= maxv[j] for all j
        REP(j, n) if(i != j && !(minv[i] >= maxv[j])) b1 = false;
        bool b2 = false; // surely not <-> maxv[i] < minv[j] for some j
        REP(j, n) if(i != j && maxv[i] < minv[j]) b2 = true;
        assert(!b1 || !b2);
        if(b1) cout << 0 << endl;
        else if(b2) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}