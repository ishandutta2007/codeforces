#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    char c[4][4];
    int a[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> c[i][j];
            switch(c[i][j]){
                case '.': a[i][j] = 0; break;
                case 'x': a[i][j] = 1; break;
                case 'o': a[i][j] = -1; break;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[i][j];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = 0; i < 4; i++){
        sum = 0;
        for(int j = 1; j < 4; j++){
            sum += a[i][j];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 4; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[j][i];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 4; i++){
        sum = 0;
        for(int j = 1; j < 4; j++){
            sum += a[j][i];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 2; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[i + j][j];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 2; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[i + j][j + 1];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    // 7-8



    for(int i = 0; i < 2; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[i + j][3 - j];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 2; i++){
        sum = 0;
        for(int j = 0; j < 3; j++){
            sum += a[i + j][2 - j];
        }
        if(sum == 2){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}