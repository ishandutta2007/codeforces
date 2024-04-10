#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, k;
    cin >> b >> k;
    vector<int> v(k);
    for (auto& x : v)
        cin >> x;
    int number = 0;
    for (int x : v)
        number = (number * b + x) % 2;
    if (number)
        cout << "odd" << '\n';
    else
        cout << "even" << '\n';
        
}