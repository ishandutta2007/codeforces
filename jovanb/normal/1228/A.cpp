#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

map <int, int> ima;

bool dif(int x){
    ima.clear();
    while(x){
        if(ima[x%10]) return 0;
        ima[x%10] = 1;
        x /= 10;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int l, r;
    cin >> l >> r;
    for(int i=l; i<=r; i++){
        if(dif(i)){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}