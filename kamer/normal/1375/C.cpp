#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int first, last;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (i == 0) first = a;
            if (i== n-1) last = a;
        }
        if (first < last) cout << "YES\n";
        else cout << "NO\n";
    }
}