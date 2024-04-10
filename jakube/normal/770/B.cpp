#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    int cnt = 0;
    for (char c : s) 
        cnt += c - '0';

    long long result = 0;
    for (char c : s) 
        result = 10 * result + (c - '0');

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;

        // start changing at i
        long long number = 0;
        int thiscnt = 0;

        for (int j = 0; j < i; j++) {
            number = 10 * number + (s[j] - '0');
            thiscnt += s[j] - '0';
        }

        number = 10 * number + (s[i] - '1');
        thiscnt += s[i] - '1';

        for (int j = i + 1; j < s.size(); j++) {
            number = 10 * number + 9;
            thiscnt += 9;
        }

        if (thiscnt > cnt || (thiscnt == cnt && number > result)) {
            cnt = thiscnt;
            result = number;
        }
    }

    cout << result << endl;
}