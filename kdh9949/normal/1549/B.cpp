#include <iostream>
using namespace std;

char a[200010], b[200010];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n >> a >> b;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] == '0') continue;
            if(i > 0 && a[i - 1] == '1') ans++;
            else if(a[i] == '0') ans++;
            else if(i < n - 1 && a[i + 1] == '1') { ans++; a[i + 1] = '2'; }
        }
        cout << ans << '\n';
    }
}