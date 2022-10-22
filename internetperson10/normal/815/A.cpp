#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int mrow[101], mcol[101];

int main() {
    bool impossible = false;
    int r, c, least=999, ans=0;
    cin >> r >> c;
    int poss = r+c;
    for(int i = 0; i < r; i++) {
        mrow[i]=999;
        for(int j = 0; j < c; j++) {
            mcol[j]=999;
            cin >> arr[i][j];
            least = min(least, arr[i][j]);
        }
    }
    if(least > 0) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                arr[i][j] -= least;
            }
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            mrow[i] = min(mrow[i], arr[i][j]);
            mcol[j] = min(mcol[j], arr[i][j]);
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            arr[i][j] -= (mrow[i] + mcol[j]);
            if(arr[i][j]) impossible = true;
        }
    }
    if(impossible) {
        cout << -1;
        return 0;
    }
    else {
        for(int i = 0; i < r; i++) ans += (mrow[i]);
        for(int j = 0; j < c; j++) ans += (mcol[j]);
        ans += min(r, c)*least;
        cout << ans << '\n';
        if(least > 0) {
            if(r < c) {
                for(int i = 0; i < r; i++) {
                    for(int k = 0; k < least; k++) cout << "row " << i+1 << '\n';
                }
            }
            else {
                for(int i = 0; i < c; i++) {
                    for(int k = 0; k < least; k++) cout << "col " << i+1 << '\n';
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int k = 0; k < mrow[i]; k++) cout << "row " << i+1 << '\n';
        }
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < mcol[j]; k++) cout << "col " << j+1 << '\n';
        }
    }
}