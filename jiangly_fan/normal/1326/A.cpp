#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        if(n == 1) cout << "-1\n";
        else if((n - 1) % 9 != 0){
            for(int i = 1; i < n; i += 1) cout << 2;
            cout << "9\n";
        }
        else{
            for(int i = 1; i < n - 1; i += 1) cout << 2;
            cout << "49\n";
        }
    }
    return 0;
}