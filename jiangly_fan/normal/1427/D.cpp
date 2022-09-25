#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 53;
int a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    vector<vector<int>> ans;
    while(true){
        int c = 0, R = 0;
        for(int j = 1; j <= n; j += 1)
            for(int k = j + 1; k <= n; k += 1)
                if(a[j] == a[k] + 1){
                    R = k;
                    c = j;
                }
        if(c == 0) break;
        int L = R;
        while(L > 1 and a[L - 1] + 1 == a[L]) L -= 1;
        ans.push_back({});
        vector<vector<int>> b;
        if(c > 1){
            ans.back().push_back(c - 1);
            b.push_back({});
            for(int i = 1; i < c; i += 1) b.back().push_back(a[i]);
        }
        ans.back().push_back(L - c);
        b.push_back({});
        for(int i = c; i < L; i += 1) b.back().push_back(a[i]);
        ans.back().push_back(R - L + 1);
        b.push_back({});
        for(int i = L; i <= R; i += 1) b.back().push_back(a[i]);
        if(n > R){
            ans.back().push_back(n - R);
            b.push_back({});
            for(int i = R + 1; i <= n; i += 1) b.back().push_back(a[i]);
        }
        reverse(b.begin(), b.end());
        int k = 0;
        for(auto v : b)
            for(int x : v) a[k += 1] = x;
        //for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
        //cout << endl;
    }
    assert(ans.size() <= n);
    cout << ans.size() << "\n";
    for(auto v : ans){
        cout << v.size() << " ";
        for(int x : v) cout << x << " ";
        cout << "\n";
    }
    return 0;
}