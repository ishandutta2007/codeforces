#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
constexpr int maxn = 100000 + 2;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for(cin >> t; t; t -= 1){
        int n, l;
        cin >> n >> l;
        a[0] = 0;
        a[n + 1] = l;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        LD L = 0, R = 1E9;
        while(R - L > 1E-7 * max(L, (LD)1)){
            LD M = (L + R) / 2;
            LD sL = 0, tL = M, sR = l, tR = M;
            for(int i = 1; i <= n + 1; i += 1){
                if(tL * i <= a[i] - a[i - 1]){
                    sL += tL * i;
                    break;
                }
                else{
                    LD t = (a[i] - a[i - 1]) / (LD)i;
                    tL -= t;
                    sL = a[i];
                }
            }
            for(int i = n; i >= 0; i -= 1){
                if(tR * (n + 1 - i) <= a[i + 1] - a[i]){
                    sR -= tR * (n + 1 - i);
                    break;
                }
                else{
                    LD t = (a[i + 1] - a[i]) / LD(n + 1 - i);
                    tR -= t;
                    sR = a[i];
                }
            }
            if(sR <= sL) R = M;
            else L = M;
        }
        cout << L << "\n";
    }
    return 0;
}