#include <bits/stdc++.h>
using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> div(50000001, 1);
    int n = div.size();

    for (int i = 2; i < n; i++) {
        div[i] = i;
    }

    for(int i = 2; i*i <= n; i++) {
        if (div[i] < i) continue;
        for (int j = i * i; j < n; j += i)
            div[j] = i;
    }

    div[0] = 0;
    div[1] = 0;
    for (int i = 2; i < n; i++) {
        div[i] = div[i / div[i]] + 1;
    }

    for (int i = 1; i < n; i++) {
        div[i] = div[i-1] + div[i];
    }

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << div[a] - div[b] << '\n';
    }

    return 0;
}