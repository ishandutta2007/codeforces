#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(i){
            cout << " that ";
        }
        if(i % 2){
            cout << "I love";
        }else{
            cout << "I hate";
        }
    }
    cout << " it" << endl;
    return 0;
}