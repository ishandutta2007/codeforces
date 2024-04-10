#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int dp[1005][1005];
int niz[1005];
int pos[1005];
int prvi[1005];

int len;

const int MOD = 998244353;

int add(int a, int b){
    return (a+b) % MOD;
}

int mul(int a, int b){
    return (1LL *a * b) % MOD;
}


int resi(int l, int r){
    if(l > r) return dp[l][r] = 1;
    if(l == r){
        if(prvi[niz[l]] < l || pos[niz[l]] > r) return 0;
        return 1;
    }
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    int mn = len;
    for(int i=l; i<=r; i++){
        mn = min(mn, niz[i]);
    }
    if(prvi[mn] < l || pos[mn] > r) return 0;
    vector <int> vec;
    for(int j=l; j<=r; j++){
        if(niz[j] == mn) vec.push_back(j);
    }
    int prod = 1;
    for(int i=0; i<vec.size()-1; i++){
        prod = mul(prod, resi(vec[i]+1, vec[i+1]-1));
    }
    int sum = 0;
    int res = 0;
    for(int i=l; i<=prvi[mn]; i++){
        sum = add(sum, mul(resi(l, i-1), resi(i, prvi[mn]-1)));
    }
    for(int i=r; i>=pos[mn]; i--){
        res = add(res, mul(sum, mul(resi(pos[mn]+1, i), resi(i+1, r))));
    }
    //cout << l << " " << r << " " << res << " " << prod << endl;
    dp[l][r] = mul(res, prod);
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        if(x != niz[len]) niz[++len] = x;
    }
    if(len > 2*n){
        cout << 0;
        return 0;
    }
    for(int i=1; i<=len; i++){
        for(int j=1; j<=len; j++){
            dp[i][j] = -1;
        }
    }
    for(int i=1; i<=len; i++){
        if(!prvi[niz[i]]) prvi[niz[i]] = i;
        pos[niz[i]] = i;
    }
    cout << resi(1, len);
    return 0;
}