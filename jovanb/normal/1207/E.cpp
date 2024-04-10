#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int res = 0;
    cout << "? ";
    for(int i=1; i<=100; i++){
        cout << i << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    for(int i=13; i>=7; i--){
        if((1 << i) & x) res += (1 << i);
    }
    cout << "? ";
    for(int i=1; i<=100; i++){
        cout << i*(1 << 7) << " ";
    }
    cout << endl;
    cin >> x;
    for(int i=6; i>=0; i--){
        if((1 << i) & x) res += (1 << i);
    }
    cout << "! " << res << endl;
    return 0;
}