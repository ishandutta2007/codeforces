#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> result;
    for (int i = 1; i < n; i+=2) {
        result.push_back(i);
    }
    for (int i = 0; i < n; i+=2) {
        result.push_back(i);
    }
    for (int i = 1; i < n; i+=2) {
        result.push_back(i);
    }
    cout << result.size() << endl;
    for (int i : result) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}