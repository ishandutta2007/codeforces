#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int a, b, c;
    cin >> a >> b >> c;
    
    vector<long long> A;
    vector<long long> B;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        string tmp;
        cin >> tmp;
        if (tmp == "USB") A.push_back(price);
        else B.push_back(price);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    long long total = 0;
    int cnt = 0;

    while (a && !A.empty()) {
        total += A.back();
        A.pop_back();
        a--;
        cnt++;
    }

    while (b && !B.empty()) {
        total += B.back();
        B.pop_back();
        b--;
        cnt++;
    }

    vector<long long> together;
    together.reserve(A.size() + B.size());
    together.insert(together.begin(), A.begin(), A.end());
    together.insert(together.begin(), B.begin(), B.end());
    sort(together.begin(), together.end());
    reverse(together.begin(), together.end());

    while (c && !together.empty()) {
        total += together.back();
        together.pop_back();
        c--;
        cnt++;
    }
    
    cout << cnt << ' ' << total << endl;
    
    return 0;
}