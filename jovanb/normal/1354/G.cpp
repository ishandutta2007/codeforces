#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int check(int l1, int r1, int l2, int r2){
    cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
    for(int i=l1; i<=r1; i++) cout << i << " ";
    cout << endl;
    for(int i=l2; i<=r2; i++) cout << i << " ";
    cout << endl;
    string s;
    cin >> s;
    if(s == "FIRST") return 1;
    else if(s == "SECOND") return -1;
    else if(s == "EQUAL") return 0;
    else exit(0);
}

void trazi(int l0, int r0){
    int p = r0;
    int l = l0, r = r0;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(l0 - (mid - l0 + 1), l0 - 1, l0, mid) == 1){
            r = mid - 1;
            p = mid;
        }
        else l = mid + 1;
    }
    cout << "! " << p << endl;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int t = 25;
    int tb = 1;
    while(t--){
        int x = rnd()%n + 1;
        if(x == tb){
            t++;
            continue;
        }
        else{
            if(check(x, x, tb, tb) == 1) tb = x;
        }
    }
    if(tb != 1){
        if(check(1, 1, tb, tb) == -1){
            cout << "! 1" << endl;
            return;
        }
    }
    tb = 1;
    while(2*tb <= n){
        int k = check(1, tb, tb + 1, 2*tb);
        if(k == 1){
            trazi(tb + 1, 2*tb);
            return;
        }
        tb *= 2;
    }
    trazi(tb + 1, n);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}