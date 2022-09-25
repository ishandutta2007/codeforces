#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 120000;
int a[maxn];
int suf[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = -1, ansi = 0;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    for(int i = n; i; i -= 1) suf[i] = suf[i + 1] | a[i];
    for(int i = 1, p = 0; i <= n; i += 1){
        int pans = (a[i] | (p | suf[i + 1])) - (p | suf[i + 1]);
        if(pans > ans){
            ans = pans;
            ansi = i;
        }
        p |= a[i];
    }
    cout << a[ansi];
    for(int i = 1; i <= n; i += 1) if(i != ansi) cout << " " << a[i];
    return 0;
}