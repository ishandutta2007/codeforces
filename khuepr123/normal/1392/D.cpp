#include<bits/stdc++.h>
using namespace std;

#define ll long long
char c[200012]; ll sum; ll s1, s2; bool x; ll temp;

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t; ll n;
    while(t--){
        cin >> n; sum = 0; x = 1; cin >> c[1];
        for(int i = 2; i <= n; i++){
            cin >> c[i];
            if(c[i] - c[i - 1]){
                x = 0;
            }
        }
        if(x){
            n = (n + 2) / 3;
            cout << n << "\n"; continue;
        }
        if(n < 3){
            cout << 0 << "\n"; continue;
        }
        temp = 0;
        if(c[1] - c[n]){
            s1 = 0, s2 = n;
        }
        else{
            for(int i = 2; i <= n; i++){
                if(c[i] - c[i - 1]){
                    s1 = i; break;
                }
            }
            for(int i = n - 1; i > 0; i--){
                if(c[i] - c[i + 1]){
                    s2 = i; break;
                }
            }
            sum = (n - (s2 - s1 + 1)) / 3;
        }
        temp = 1;
        for(int i = s1 + 1; i <= s2; i++){
            if(c[i] - c[i - 1]){
                temp = temp / 3;
                sum = sum + temp;
                temp = 1;
            }
            else{
                temp = temp + 1;
            }
        }
        temp = temp / 3;
        sum = sum + temp; cout << sum << "\n";
    }
}