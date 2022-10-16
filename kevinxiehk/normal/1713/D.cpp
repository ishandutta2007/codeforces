#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
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
void gay(int TC) {cout << "Case #" << TC << ": ";}
int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cin >> a;
    return a;
}
void solve(int TC) {
    int n;
    cin >> n;
    queue<int> aaa;
    for(int i = 1; i <= (1 << n); i++) aaa.push(i);
    int arr[5];
    while(aaa.size() > 2) {
        for(int i = 0; i <= 3; i++) {
            arr[i] = aaa.front();
            aaa.pop();
        }
        int k = ask(arr[0], arr[2]);
        if(k == 0) {
            int kk = ask(arr[1], arr[3]);
            if(kk == 1) aaa.push(arr[1]);
            else aaa.push(arr[3]);
        }
        else if(k == 1) {
            int kk = ask(arr[0], arr[3]);
            if(kk == 1) aaa.push(arr[0]);
            else aaa.push(arr[3]);
        }
        else {
            int kk = ask(arr[1], arr[2]);
            if(kk == 1) aaa.push(arr[1]);
            else aaa.push(arr[2]);
        }
    }
    if(aaa.size() == 2) {
        int a = aaa.front();
        aaa.pop();
        int b = aaa.front();
        aaa.pop();
        if(ask(a, b) == 1) aaa.push(a);
        else aaa.push(b);
    }
    cout << "! " << aaa.front() << endl;;
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}