#include<bits/stdc++.h>
#define int long long

using namespace std;
main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int kol = 0;
    for (int i = 1; i <= n; i++){
        int x1 = i;
        int x2 = i + b - c;
        int x3 = i + a + b - c - d;
        int x4 = i + a - d;
        if (x1 <= n && x2 <= n && x3  <= n && x4 <= n && x1 >= 1 && x2 >= 1 && x3 >= 1 && x4 >= 1){
            kol += n;
        }
    }
    cout << kol;
}