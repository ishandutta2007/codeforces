#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    auto start = chrono::system_clock::now();
    while (1) {
        auto end = chrono::system_clock::now();
        auto dur = end - start;
        
        if (chrono::duration_cast<chrono::milliseconds>(dur).count() > 1234)
            break;
    }
    
    
    for (int i : v)
        cout << i << " ";
    cout << endl;
}