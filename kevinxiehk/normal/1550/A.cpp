#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int n, arr[1000005];    
vector<int> conn[1000005];
bool vi[1000005];
void init(int k) {
    for(int i = 0; i <= k; i++) {
        arr[i] = 0;
        vi[i] = false;
        conn[i].clear();
    }
}
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
void solve() {  
    cin >> n;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < 1000000; i++) {
        sum += (i * 2) + 1;
        cnt++;
        if(sum >= n) {
            cout << cnt << '\n';
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}