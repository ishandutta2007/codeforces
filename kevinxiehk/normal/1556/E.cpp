#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
int arr[100005];
int sps1[100005][25], sps2[100005][25];
int mi(int l, int r) {
    int dif = r - l + 1;
    int cnt = -1;
    while(dif) {
        dif /= 2;
        cnt++;
    }
    return min(sps1[l][cnt], sps1[r - (1 << cnt) + 1][cnt]);
}
int mx(int l, int r) {
    int dif = r - l + 1;
    int cnt = -1;
    while(dif) {
        dif /= 2;
        cnt++;
    }
    return max(sps2[l][cnt], sps2[r - (1 << cnt) + 1][cnt]);
}
void doo(int l, int r) {
    int mm = mx(l - 1, r), mmm = mi(l - 1, r);
    if(sps1[l - 1][0] != sps1[r][0] || mmm < sps1[l-1][0]) {
        cout << "-1\n";
        return;
    }
    cout << mm - sps1[l - 1][0] << '\n';
}
int n, q;
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int t;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        arr[i] = t - arr[i] + arr[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        sps1[i][0] = arr[i];
    }
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j <= n; j++) {
            sps1[j][i] = min(sps1[j][i - 1], sps1[min(j + (1 << (i - 1)), n)][i - 1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        sps2[i][0] = arr[i];
    }
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j <= n; j++) {
            sps2[j][i] = max(sps2[j][i - 1], sps2[min(j + (1 << (i - 1)), n)][i - 1]);
        }
    }
    int l, r;
    while(q--) {
        cin >> l >> r;
        doo(l, r);
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}