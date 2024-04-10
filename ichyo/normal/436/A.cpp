#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, x;
    while(cin >> n >> x){
        vector<pair<int, int>> p[2];
        REP(i, n) {
            int t;
            cin >> t;
            int h, m;
            cin >> h >> m;
            p[t].push_back(make_pair(h, m));
        }
        int ans = 0;
        REP(_, 2) {
            int cnt = 0;
            vector<bool> used1(n);
            vector<bool> used2(n);
            int k = 0;
            int power = x;
            while(true){
                int max_i = -1;
                const vector<pair<int, int>>& v = p[k];
                vector<bool>& used = (k == 0 ? used1 : used2);
                for(int i = 0; i < v.size(); i++){
                    if(!used[i] && power >= v[i].first && (max_i == -1 || v[i].second > v[max_i].second)){
                        max_i = i;
                    }
                }
                if(max_i == -1) {
                    break;
                }
                used[max_i] = true;
                power += v[max_i].second;
                cnt++;

                k ^= 1;
            }
            ans = max(ans, cnt);
            swap(p[0], p[1]);
        }
        cout << ans << endl;
    }
    return 0;
}