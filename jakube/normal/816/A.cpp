#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int hrs = (s[0] - '0') * 10 + (s[1] - '0');
    int min = (s[3] - '0') * 10 + (s[4] - '0');
    
    for (int i = 0; i < 100000; i++) {
        if (hrs / 10 == min % 10 && hrs % 10 == min / 10) {
            cout << i << endl;
            return 0;
        }

        min++;
        if (min == 60) {
            min = 0;
            hrs++;
        }
        if (hrs == 24)
            hrs = 0;
    }
}