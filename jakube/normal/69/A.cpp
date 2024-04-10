#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    
    int x = 0;
    int y = 0;
    int z = 0;

    for (int i = 0; i < N; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        x += X;
        y += Y;
        z += Z;
    }
    
    if (x == 0 && y == 0 && z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}