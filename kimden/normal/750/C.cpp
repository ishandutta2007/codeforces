#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll q = 1000000000000LL;

int main(){
    int n;
    cin >> n;
    ll lower, upper;
    upper = 2 * q;
    lower = -2 * q;
    ll c;
    int d;
    for(int i = 0; i < n; i++){
        cin >> c >> d;
        if(d == 1){
            lower = max(lower, 1900LL);
        }else{
            upper = min(upper, 1899LL);
        }
        lower += c;
        upper += c;
        if(lower > upper){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(upper > q){
        cout << "Infinity" << endl;
    }else{
        cout << upper << endl;
    }
    return 0;
}