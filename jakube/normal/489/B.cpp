#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    int m;
    cin >> m;
    vector<int> w(m);
    for (int idx = 0; idx < m;  idx++)
        cin >> w[idx];
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    int i = 0; 
    int j = 0;
    int c = 0;
    while (i < v.size() && j < w.size()) {
        if (abs(v[i]-w[j]) <= 1) {
            i++;
            j++;
            c++;
        }
        else if (v[i] > w[j]) {
            j++;
        }
        else if (v[i] < w[j]) {
            i++;
        }
    }

    cout << c << endl;

    return 0;
}