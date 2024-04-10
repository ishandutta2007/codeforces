#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int main(){
    int n, p;
    while(cin >> n >> p) {
        map<P, int> cnt_p;
        vector<int> cnt_i(n);
        
        REP(i, n) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            if(a > b) swap(a, b);
            cnt_p[P(a, b)] += 1;
            cnt_i[a] ++;
            cnt_i[b] ++;
        }

        long long ans = 0;
        vector<int> cnt_s = cnt_i;
        sort(cnt_s.begin(), cnt_s.end());

        for(int i = 0; i < n; i++) {
            int c = cnt_i[i];
            int rest = p - c;
            int k = lower_bound(cnt_s.begin(), cnt_s.end(), rest) - cnt_s.begin();
            int num = n - k;
            if(c + c >= p) num--;
            ans += num;
        }

        for(auto mp : cnt_p) {
            auto pr = mp.first;
            int c = mp.second;
            int a = pr.first, b = pr.second;
            if(cnt_i[a] + cnt_i[b] >= p && cnt_i[a] + cnt_i[b] - c < p) {
                ans -= 2;
            }
        }

        cout << ans / 2 << endl;
    }
    return 0;
}