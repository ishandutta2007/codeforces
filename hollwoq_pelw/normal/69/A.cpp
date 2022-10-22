#include <iostream>
using namespace std;
int main(){
    int n,a,b,c;
    cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if (x||y||z) cout << "NO";
    else cout << "YES";
    return 0;
}