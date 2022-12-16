#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string inp;
    cin >> inp;
    unordered_set<char> allowed;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        allowed.insert(c);
    }

    int possible[n];
    if (allowed.find(inp[0]) != allowed.end()) {
        possible[0] = 1;
    } else {
        possible[0] = 0;
    }

    for (int i = 1; i < n; i++) {
        if (allowed.find(inp[i]) == allowed.end()) {
            possible[i] = 0;
            continue;
        }
        possible[i] = possible[i-1] + 1;
    }

    uint64_t out = 0;
    for (int i = 0; i < n; i++) out += possible[i];
    cout << out << endl;
}