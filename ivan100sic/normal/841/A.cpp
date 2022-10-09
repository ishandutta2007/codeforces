
#include <bits/stdc++.h>
using namespace std;

int main() {
        int n, k; 
        string s;
        cin >> n >> k >> s;
        vector<int> c(256, 0);
        for (char x : s) {
                c[x]++;
        }
        cout <<  (*max_element(c.begin(), c.end()) <= k ? "YES" : "NO");
}