#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero = 0;
    int one = 0;
    for (char c : s) {
        if (c == '0')
            zero++;
        else
            one++;
    }

    if (one)
        cout << "1";
    for (int i = 0; i < zero; i++)
        cout << "0";
    cout << '\n';
    
    
}