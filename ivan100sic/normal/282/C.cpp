#include <bits/stdc++.h>
using namespace std;
int main() {
string a, b;
cin >> a >> b;
cout << (a.size() == b.size() && !count(begin(a), end(a), '1') == !count(begin(b), end(b), '1') ? "YES\n": "NO\n");
}