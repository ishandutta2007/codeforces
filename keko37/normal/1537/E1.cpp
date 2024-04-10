#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, k;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for (int i = 1; i < k; i++) {
        while (s.size() > k) s.pop_back();
        while (s.size() < k) s.push_back('z' + 1);
        if (s < s.substr(i)) {
            while (s.size() > i) s.pop_back();
            s = s + s;
        }
    }
    while (s.size() > k) s.pop_back();
    cout << s;
    return 0;
}