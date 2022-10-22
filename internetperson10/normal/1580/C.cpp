#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<int, int>> v;
vector<vector<int>> ct;
vector<int> ct2, orig;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    v.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int boun = (int)(sqrt(2*m));
    if(boun < 0) boun++;
    ct.resize(boun+1);
    for(int i = 1; i <= boun; i++) ct[i].resize(i);
    ct2.resize(2*m+1);
    orig.resize(n+1);
    int tr = 0;
    for(int i = 1; i <= m; i++) {
        int op, k;
        cin >> op >> k;
        int g = v[k].first + v[k].second;
        int x = v[k].first;
        int y = v[k].second;
            if(op == 1) {
                int tim = i;
                orig[k] = tim;
                if(g <= boun) {
                    ct[g][(tim+x)%g]++;
                    ct[g][tim%g]--;
                    tr++;
                }
                else {
                    for(int j = tim+x; j <= 2*m; j += g) ct2[j]++;
                    for(int j = tim+x+y; j <= 2*m; j += g) ct2[j]--;
                }
            }
            else {
                int tim = orig[k]; 
                if(g <= boun) {
                    ct[g][(tim+x)%g]--;
                    ct[g][tim%g]++;
                }
                else {
                    for(int j = tim+x; j <= 2*m; j += g) ct2[j]--;
                    for(int j = tim+x+y; j <= 2*m; j += g) ct2[j]++;
                }
                int k = (i-tim)%g;
                if(k == 0 || k > x) tr--;
            }
        tr += ct2[i];
        for(int j = 1; j <= boun; j++) {
            tr += ct[j][i%j];
        }
        cout << tr << '\n';
    }
}