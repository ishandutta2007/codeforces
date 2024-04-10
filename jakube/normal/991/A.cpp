#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, N;
    cin >> A >> B >> C >> N;
    
    int D = N - (A + B - C);
    if (A >= C && B >= C && D >= 1)
        cout << D << '\n';
    else
        cout << -1 << '\n';
}