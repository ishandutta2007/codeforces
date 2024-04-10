#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, d;
        cin >> n >> d;
        for(int i = 0; i < n; i += 1) cin >> a[i];
        for(int i = 1; i < n; i += 1){
            while(d >= i and a[i]){
                a[0] += 1;
                a[i] -= 1;
                d -= i;
            }
        }
        cout << a[0] << "\n";
    }
    return 0;
}