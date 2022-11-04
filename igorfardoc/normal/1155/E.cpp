#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000003;

int bin_pow(int a, int b) {
    if(b == 0) return 1;
    int res = bin_pow(a, b >> 1);
    res = ((ll)res * res) % mod;
    if(b & 1) {
        res = ((ll)res * a) % mod;
    }
    return res;
}

int obr(int a) {
    return bin_pow(a, mod - 2);
}

int q(int a) {
    cout << "? " << a << endl;
    int res;
    cin >> res;
    return res;
}

int gauss (vector<vector<int>> a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if(a[i][col] > a[sel][col])
                sel = i;
        if(a[sel][col] == 0)
            continue;
        for(int i=col; i<=m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = (ll)a[i][col] * obr(a[row][col]) % mod;
                for (int j=col; j<=m; ++j)
                    a[i][j] = (a[i][j] - (ll)a[row][j] * c % mod + mod) % mod;
            }
        ++row;
    }
 
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (ll)a[where[i]][m] * obr(a[where[i]][i]) % mod;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + (ll)ans[j] * a[i][j]) % mod;
        if (sum != a[i][m])
            return 0;
    }
 
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int k = 10;
    vvi a;
    for(int i = 0; i <= k; i++) {
        vi here;
        int now = 1;
        for(int j = 0; j <= k; j++) {
            here.push_back(now);
            now = (ll)now * i % mod;
        }
        here.push_back(q(i));
        a.push_back(here);
    }
    vi ans;
    gauss(a, ans);
    /*for(const auto& el : ans) {
        cout << el << ' ';
    }
    cout << endl;*/
    for(int i = 0; i < mod; i++) {
        int res = 0;
        int now = 1;
        for(int j = 0; j <= k; j++) {
            res = (res + (ll)now * ans[j]) % mod;
            now = (ll)now * i % mod;
        }
        if(res == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;
}