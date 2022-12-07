#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 2e+5;
int n;
vector<int> M(MAXN, 0), K(MAXN, 0);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M[i] >> K[i];
    }
    long long ans_zi = 0, ans_mu = 1;
    vector<int> ans;
    for (int ti = 1; ti <= 20; ti++) {
        vector<int> count(MAXN, 0);
        for (int i = 0; i < n; i++)
            count[M[i]] += min(K[i], ti);
        vector<pii> tmp;
        for (int i = 0; i < MAXN; i++) {
            tmp.push_back(make_pair(count[i], i));
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        
        long long zi = 0, mu = ti;
        for (int j = 0; j < ti; j++) {
            zi += tmp[j].first;
        }
        if (zi * ans_mu > ans_zi * mu) {
            ans_zi = zi;
            ans_mu = mu;
            ans.clear();
            for (int j = 0; j < ti; j++) {
                ans.push_back(tmp[j].second);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}