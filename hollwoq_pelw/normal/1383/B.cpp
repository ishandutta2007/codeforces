#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[32];
int main(){
    cin >> t; while(t--){
        cin >> n;
        for (int i = 0; i < 32; i++){
            cnt[i] = 0;
        }
        for (int i = 0, a; i < n; i++){
            cin >> a;
            for (int j = 0; j < 32; j++){
                cnt[j] += ((a >> j) & 1);
            }
        }
        for (int i = 31; i >= 0; i--){
            if (cnt[i] % 2 == 0){
                continue;
            }
            if (cnt[i] % 4 == 1 || (n - cnt[i]) % 2 == 1){
                cout << "WIN\n";
            }else{
                cout << "LOSE\n";
            }
            goto next;
            
        }
        cout << "DRAW\n";
        next:;
    }
}