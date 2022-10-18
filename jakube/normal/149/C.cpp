#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    vector<int> A, B;
    int a = 0;
    int b = 0;
    int sumA = 0;
    int sumB = 0;

    int i = 0;
    int j = n;
    while (i < j) {
        if (sumA < sumB) {
            if (A.size() <= B.size()) {
                sumA += v[i].first;
                A.push_back(v[i].second);
                i++;
            } else {
                j--;
                sumB += v[j].first;
                B.push_back(v[j].second);
            }
        } else {
            if (B.size() <= A.size()) {
                sumB += v[i].first;
                B.push_back(v[i].second);
                i++;
            } else {
                j--;
                sumA += v[j].first;
                A.push_back(v[j].second);
            }
        }
    }

    cout << A.size() << endl;
    for (int i : A)
        cout << i << ' ';
    cout << endl;
    cout << B.size() << endl;
    for (int i : B)
        cout << i << ' ';
    cout << endl;
    
}