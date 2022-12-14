#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)104;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int d, k; cin >> d >> k;
        LL val = ((LL)d * d) / ((LL)k * k);
        LL x = sqrt(val) / 2, y = sqrt(val) / 2;
        while((x + 1) * (x + 1) + (y + 1) * (y + 1) <= val){
            ++y; ++x;
        }
        while(x * x + (y + 1) * (y + 1) <= val){
            ++y;
        }
//        cout << val << ' ' << x << ' ' << y << endl;
        if((x + y) % 2){
            cout << "Ashish\n";
        }
        else{
            cout << "Utkarsh\n";
        }
    }
    return 0;
}