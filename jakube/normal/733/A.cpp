#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    s += 'A';

    int largest = 0;
    int cur = 0;
    string vovels = "AEIOUY";
    for (int i = 0; i < s.size(); i++) {
        cur++;
        largest = max(largest, cur);
        if (vovels.find(s[i]) != string::npos) 
            cur = 0;
    }

    cout << largest << endl;

    return 0;
}