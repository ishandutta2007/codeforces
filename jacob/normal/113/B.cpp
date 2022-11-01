#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long ui64;

ui64 MUL = 41;

ui64 MULPOWS[4000];

int main(void) {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    MULPOWS[0] = 1;
    for (int i = 1; i < 4000; i++)
        MULPOWS[i] = MULPOWS[i-1]*MUL;
    vector<ui64> ph(s1.size() + 1);
    for (int i = 0; i < (int)s1.length(); i++) {
        ph[i+1] = ph[i] * MUL + ui64(s1[i]);
    }
    ui64 h1 = 0, h2 = 0;
    for (int i = 0; i < (int)s2.length(); i++) {
        h1 = h1*MUL + ui64(s2[i]);
    }
    for (int i = 0; i < (int)s3.length(); i++) {
        h2 = h2*MUL + ui64(s3[i]);
    }
    int l1 = (int)s2.length();
    int l2 = s3.length();
    vector<ui64> v;
    for (int i = 0; i <= (int)s1.length() - l1; i++) {
        if (ph[i + l1] - ph[i] * MULPOWS[l1] != h1) continue;
        for (int j = i + max(l1, l2); j <= s1.length(); j++) {
            if (ph[j] - ph[j-l2] * MULPOWS[l2] != h2) continue;
            v.push_back(ph[j] - ph[i] * MULPOWS[j - i]);
        }
    }
    sort(v.begin(), v.end());
    cout << (unique(v.begin(), v.end()) - v.begin()) << endl;
    return 0;
}