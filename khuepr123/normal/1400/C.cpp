#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000009;
int x, n; string s;
bool a[300027];
bool b[300027];
bool chk;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> s >> x; n = s.length(); chk = 1;
        for(int i = 1; i <= x; i++){
            a[i] = 0;
            b[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(s[i] - 48){
                a[x + 1 + i] = 1;
            }
            else{
                a[x + 1 + i] = 0;
            }
            b[x + 1 + i] = 1;
        }
        n = (x * 2) + n;
        for(int i = n - x + 1; i <= n; i++){
            a[i] = 0; b[i] = 0;
        }
        n = n - (x * 2);
        for(int i = x + 1; i <= x + n; i++){
            if(a[i] - 1){
                b[i - x] = 0; b[i + x] = 0;
            }
        }
        for(int i = x + 1; i <= x + n; i++){
            if(a[i]){
                if(b[i - x] || b[i + x]){
                    continue;
                }
                chk = 0; cout << -1; break;
            }
        }
        if(chk){
            for(int i = x + 1; i <= x + n; i++){
                cout << b[i];
            }
        }
        cout << "\n";
    }
}