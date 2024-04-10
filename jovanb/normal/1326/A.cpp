#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            cout << -1 << "\n";
        }
        else{
            cout << 5;
            for(int j=1; j<x; j++) cout << "3";
            cout << "\n";
        }
    }
    return 0;
}