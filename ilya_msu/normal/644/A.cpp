#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int> > res(a, vector<int>(b, 0));
    for (int i = 0; i < n; ++i) {
        res[i / b][i % b] = i + 1;
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if (i & 1)
                cout << res[i][b - j - 1] << " ";
            else
                cout << res[i][j] << " ";


        }
        cout << endl;
    }
    return 0;
}