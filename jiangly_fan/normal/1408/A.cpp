#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn], b[maxn], c[maxn], p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> a[i];
        for(int i = 0; i < n; i += 1) cin >> b[i];
        for(int i = 0; i < n; i += 1) cin >> c[i];
        for(int i = 0; i < n; i += 1){
            if(i == 0) p[i] = a[i];
            else if(i + 1 < n){
                if(a[i] != p[i - 1]) p[i] = a[i];
                else if(b[i] != p[i - 1]) p[i] = b[i];
                else if(c[i] != p[i - 1]) p[i] = c[i];
            }
            else{
                if(a[i] != p[i - 1] and a[i] != p[0]) p[i] = a[i];
                else if(b[i] != p[i - 1] and b[i] != p[0]) p[i] = b[i];
                else if(c[i] != p[i - 1] and c[i] != p[0]) p[i] = c[i];
            }
        }
        for(int i = 0; i < n; i += 1) cout << p[i] << " ";
        cout << "\n";
    }
    return 0;
}