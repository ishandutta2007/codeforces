#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, m;
    int a[100020];
    cin >> n >> m;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    v.push_back(1);
    v.push_back(-1);
    v.push_back(n + 1);
    int l[305], r[305];
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        r[i]++;
        v.push_back(r[i]);
        v.push_back(l[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int max_comp[1000];
    int min_comp[1000];
    for(int i = 0; i < 1000; i++) {
        max_comp[i] = -1e7;
        min_comp[i] = 1e7;
    }
    int SIZE = v.size();
    SIZE -= 2;
    //cout << SIZE << endl;
    for(int i = 1; i <= SIZE; i++) {
        for(int j = v[i]; j < v[i + 1]; j++) {
            max_comp[i] = max(max_comp[i], a[j]);
            min_comp[i] = min(min_comp[i], a[j]);
        }
        ///cout << i << " " << max_comp[i] << " " << min_comp[i] << endl;
    }
    for(int i = 1; i <= m; i++) {
        l[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), l[i]));
        r[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), r[i]));
        //cout << i << " " << l[i] << " " << r[i] << endl;
    }
    int ans = 0;
    pair<int, int> ans_pair = {1, 1};
    for(int small = 1; small <= SIZE; small++) {
        for(int large = 1; large <= SIZE; large++) {
            int now = max_comp[large] - min_comp[small];
            for(int index = 1; index <= m; index++) {
                if((l[index] <= small) && (small < r[index])) {
                    if(!((l[index] <= large) && (large < r[index]))) {
                        now++;
                    }
                }
            }
            if(now > ans) {
                ans = now;
                ans_pair = {small, large};
            }
            //ans = max(ans, now);
        }
    }
    cout << ans << endl;
    vector<int> ANS;
    int small = ans_pair.first;
    int large = ans_pair.second;
    for(int index = 1; index <= m; index++) {
        if((l[index] <= small) && (small < r[index])) {
            ANS.push_back(index);
        }
    }
    cout << ANS.size() << endl;
    if(ANS.empty()) return 0;
    for(int i = 0; i < ANS.size(); i++) {
        cout << ANS[i];
        if(i + 1 < ANS.size()) cout << " ";
    }
    cout << endl;
    return 0;
}