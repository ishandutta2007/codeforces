#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
    int x, y, z, a, b, c;
    int n;
    cin >> n;
    x = y = z = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if(!(x || y || z)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}