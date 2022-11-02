#include <bits/stdc++.h>
using namespace std;

int n;
string s;
 
int main() {
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            return cout << "YES\n" << i << " " << i + 1, 0;
        }
    }
    cout << "NO";
}