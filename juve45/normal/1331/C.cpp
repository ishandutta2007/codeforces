#include <iostream> 
#include <string.h>

using namespace std;
int x, ans;

int main() {
    cin >> x;
    int ans = 0;
    ans += (x % 2) * 16; x /= 2; // 6
    // cerr << x << '\n';
    ans += (x % 2) * 2; x /= 2; // 5
    ans += (x % 2) * 8; x /= 2; // 4
    // cerr << x << '\n';
    ans += (x % 2) * 4; x /= 2; 
    // cerr << x << '\n';
    ans += (x % 2) * 1; x /= 2; // 2
    ans += (x % 2) * 32; x /= 2; // 1
    // ans += (x % 2) * 64; x /= 2; // 0
    cout << ans << '\n';
}