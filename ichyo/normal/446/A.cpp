#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
int solve(vector<int> a) {
    int n = a.size();

    int ans = 0;
    vector<pair<int, int>> vp;

    for(int i = 0; i < n; ) {
        int j = i + 1;
        while(j < n && a[j] > a[j - 1]) {
            j++;
        }
        vp.push_back(make_pair(i, j));
        ans = max(ans, j - i + 1);
        i = j;
    }
    vector<bool> ok(n);
    REP(i, n) if(i - 1 >= 0 && i + 1 < n && a[i - 1] + 1 < a[i + 1]) ok[i] = true;

    for(int i = 0; i < vp.size(); i++) {
        if(i - 1 >= 0 && i + 1 < vp.size() && vp[i].second == vp[i].first + 1 && ok[ vp[i].first ]) {
            ans = max(ans, vp[i + 1].second - vp[i - 1].first);
        }
        if(i + 1 < vp.size() && (ok[ vp[i + 1].first ] || ok[ vp[i].second - 1 ])) {
            ans = max(ans, vp[i + 1].second - vp[i].first);
        }
    }

    if(ans > n) ans = n;

    return ans;
}

bool inc(vector<int>& b) {
    REP(i, b.size() - 1) if(b[i] >= b[i + 1]) return false;
    return true;
}

int slow(vector<int> a) {
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        vector<int> b;
        for(int j = i; j < a.size(); j++) {
            b.push_back(a[j]);
            for(int k = 0; k < b.size(); k++) {
                int tmp = b[k];
                if(k == 0) {
                    b[k] = -1;
                } else {
                    b[k] = b[k - 1] + 1;
                }
                if(inc(b)) {
                    ans = max(ans, (int)b.size());
                }
                b[k] = tmp;
            }
        }
    }
    return ans;
}

vector<int> random(int n) {
    vector<int> res(n);
    REP(i, n) res[i] = rand() % 100 + 1;
    return res;
}


int main(){
    int n;
    cin >> n;
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    cout << solve(b) << endl;

    // REP(_, 100) {
    //     vector<int> a = random(50);
    //     if(slow(a) != solve(a)) {
    //         cout << "a: ";
    //         REP(i, a.size()) cout << a[i] << " "; cout << endl;
    //         cout << "slow: "; cout << slow(a) << endl;
    //         cout << "solve: "; cout << solve(a) << endl;
    //     }
    // }

    return 0;
}