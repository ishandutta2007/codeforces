#include <iostream>
#include <vector>
#include <functional>
#include <cstdio>
#include <climits>
#include <string>
using namespace std;

int main() {
    string t;
    cin >> t;
    int del = 0;
    int now = (t.size() - 1) / 2 + 1 - 1;
    while (now >= 0 && now < t.size()) {
        cout << t[now];
        if (del <= 0) {
            del -= 1;
        } else {
            del += 1;
        }
        del *= -1;
        now += del;
    }
    return 0;
}