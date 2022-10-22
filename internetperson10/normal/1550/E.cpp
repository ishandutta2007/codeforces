#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool good(string s, int k, int c) {
    if(!c) return false;
    int n = s.size();
    vector<vector<int>> v(k);
    for(int i = 0; i < k; i++) {
        v[i].resize(n);
        v[i][0] = -1;
        int g = 0; 
        for(int j = 0; j < n; j++) {
            if(s.at(j) == 'a' + i || s.at(j) == '?') {
                g++;
            }
            else {
                g = 0;
            }
            if(g >= c) v[i][j] = j;
            else if(j) v[i][j] = v[i][j-1];
        }
    }
    vector<int> ans((1 << k));
    ans[0] = n-1+c;
    for(int i = 1; i < ans.size(); i++) {
        ans[i] = -1;
        for(int j = 0; j < k; j++) {
            if(i & (1 << j)) {
                if(ans[i ^ (1 << j)] >= c) ans[i] = max(ans[i], v[j][ans[i ^ (1 << j)] - c]);
            }
        }
    }
    vector<vector<int>>().swap(v);
    return (ans.back() != -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = (n+k)/k;
    while(l != r-1) {
        int mid = (l+r)/2;
        if(good(s, k, mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}