#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    if(n%2 == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int tren = 1;
    for(int i=1; i<=n; i++){
        cout << tren << " ";
        if(i%2) tren += 3;
        else tren++;
    }
    tren = 2;
    for(int i=1; i<=n; i++){
        cout << tren << " ";
        if(i%2) tren++;
        else tren += 3;
    }
    return 0;
}