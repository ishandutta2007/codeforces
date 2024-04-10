#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200;

int p[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int posl = 0;
    for(int i=1; i<n; i++){
        cout << "? ";
        for(int j=1; j<n; j++) cout << i+1 << " ";
        cout << 1;
        cout << endl;
        int x;
        cin >> x;
        if(x == 0){
            posl = i;
            break;
        }
    }
    if(!posl) posl = n;
    p[n] = posl;
    for(int val=1; val<posl; val++){
        cout << "? ";
        for(int j=1; j<n; j++) cout << posl - val + 1 << " ";
        cout << 1;
        cout << endl;
        int x;
        cin >> x;
        p[x] = val;
    }
    for(int val=posl+1; val<=n; val++){
        cout << "? ";
        for(int j=1; j<n; j++) cout << 1 << " ";
        cout << val - posl + 1;
        cout << endl;
        int x;
        cin >> x;
        p[x] = val;
    }
    cout << "! ";
    for(int i=1; i<=n; i++) assert(p[i]);
    for(int i=1; i<=n; i++) cout << p[i] << " ";
    cout << endl;
    return 0;
}