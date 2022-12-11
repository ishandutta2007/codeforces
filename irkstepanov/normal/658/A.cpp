#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    
    int n, c;
    cin >> n >> c;
    
    vector<int> p(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    
    int a = 0, timer = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        timer += t[i];
        a += max(0, p[i] - timer * c);
    }
    timer = 0;
    for (int i = n - 1; i >= 0; --i) {
        timer += t[i];
        b += max(0, p[i] - timer * c);
    }
    
    if (a > b) {
        cout << "Limak\n";
    } else if (a == b) {
        cout << "Tie\n";
    } else {
        cout << "Radewoosh\n";
    }

}