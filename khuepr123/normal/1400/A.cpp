#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000009;
int n; string s;

int c0, c1;
int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> s;
        c0 = 0; c1 = 0;
        n = n - 1;
        n = n * 2;//deceased
        for(int i = 0; i <= n; i++){
            if(s[i] == 48){
                c0++;
            }
            else{
                c1++;
            }
        }
        n = n / 2; n = n + 1;
        if(c0 > c1){
            for(int i = 0; i < n; i++){
                cout << 0;
            }
        }
        else{
            for(int i = 0; i < n; i++){
                cout << 1;
            }
        }
        cout << "\n";
    }
}