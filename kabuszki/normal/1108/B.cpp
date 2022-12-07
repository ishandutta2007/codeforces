#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n), w;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int x = v.back();
    for (int& a : v) if (x % a == 0) {
        int b = a;
        if (w.empty() || w.back() != b) {
            w.push_back(b);
            a = 0;
        }
    }
    int y = 0;
    for (int a : v) if (a != 0) y = a;
    cout << x << " " << y << "\n";
}