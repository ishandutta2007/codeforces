#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cout << (i % 4 < 2 ? 'a' : 'b');
    cout << endl;
}