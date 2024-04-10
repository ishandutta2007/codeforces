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
void solve() {
    string s;
    int t;
    int t2 = 0;
    cin >> s >> t;
    int cnt[15];
    for(int i = 0; i <= 10; i++) cnt[i] = 0;
    for(int i = 0; i < s.length(); i++) {
        cnt[i] = s[s.length() - 1 - i] - '0';
        t2 += cnt[i];
    }
    while(t2 < t) {
        int i = 1;
        while(cnt[i] == 0) i++;
        cnt[i]--;
        cnt[i - 1] += 10;
        t2 += 9;
    }
    for(int _ = 1; _ < t; _++) {
        int i = 0;
        while(cnt[i] == 0) i++;
        cnt[i]--;
        cout << (int)pow(10, i) << ' ';
    }
    int aaa = 0;
    for(int i = 0; i < s.length(); i++) {
        aaa += cnt[i] * pow(10, i);
    }
    cout << aaa << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}