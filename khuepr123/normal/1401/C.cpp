#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000009;
int a[100005], b[100005]; int mn; bool x;

int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; int n; 
    while(o--){
        cin >> n; mn = 2147483647; x = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            b[i] = a[i];
            if(mn > a[i]){
                mn = a[i];
            }
        }
        sort(b + 1, b + n + 1);
        for(int i = 1; i <= n; i++){
            if(a[i] - b[i]){
                if(a[i] % mn){
                    cout << "NO\n"; x = 0; break;
                }
            }
        }
        if(x){
            cout << "YES\n";
        }
    }
}