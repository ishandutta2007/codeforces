#include <bits/stdc++.h>
using namespace std;


int solve() {
    int N;
    cin >> N;
    set<int> s;
    while (N--) {
        int a;
        cin >> a;
        s.insert(a);
    }
    return s.size();
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
}