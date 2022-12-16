#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int out = 0;

    for (int j = 0; j < m; j++) {
        int inPlace[n];
        for (int i = 0; i < n; i++) {
            inPlace[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int element = a[i][j] - j - 1;
            if (element % m != 0) continue;
            int desiredrow = element/m;
            if (desiredrow >= n) continue;
            //cout <<"want: " <<  a[i][j] << ' ' << desiredrow << endl;
            int neededmoves = (i-desiredrow)%n;
            if (neededmoves < 0) neededmoves += n;
            inPlace[neededmoves]++;
        }
        int colout = 1e9;
        for (int i = 0; i < n; i++) {
            colout = min(colout, i+(n-inPlace[i]));
        }
        out += colout;
        //cout << j << ' ' << colout << endl;
    }
    cout << out << endl;
}