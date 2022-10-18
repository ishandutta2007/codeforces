#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    cout << (*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) + 1 - n) << endl;
}