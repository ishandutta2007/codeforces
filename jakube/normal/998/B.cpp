#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int B;
    cin >> B;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> s;
    int bal = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] % 2)
            bal--;
        else
            bal++;
        if (bal == 0)
            s.push_back(abs(a[i] - a[i+1]));
    }
    sort(s.begin(), s.end());
    int c = 0;
    for (int x : s) {
        if (x <= B) {
            c++;
            B -= x;
        }
    }
    cout << c << '\n';
}