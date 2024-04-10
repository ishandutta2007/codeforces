#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long p_n(int a){
    if (a == 0) return 1;
    if (a == 1) return 2;
    long long x = p_n(a/2);
    return ((x*x)%mod*p_n(a%2))%mod;
}
int main(){
    int h,w;
    cin >> h >> w;
    int r[h], c[w];
    int a = 0;
    for (int i = 0; i < h; i++) cin >> r[i];
    for (int i = 0; i < w; i++) cin >> c[i];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (i>c[j] && j>r[i]) a++; // safe
            else{
                if ((i == c[j] && j < r[i]) || (j == r[i] && i < c[j])){
                    // invalid
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    cout << p_n(a);
}