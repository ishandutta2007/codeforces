#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[4][2];
int c[4][4];

int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }
    swap(a[0][1], a[1][1]);
    swap(a[2][1], a[3][1]);
    swap(a[2][0], a[2][1]);
    swap(a[3][0], a[3][1]);
    for(int i = 0; i < 2; i++){
        for(int j = 2; j < 4; j++){
            if(a[i][0] > a[j][0] && a[i][1] > a[j][1]){
                c[i][j] = 1;
                c[j][i] = -1;
            }
            if(a[i][0] < a[j][0] && a[i][1] < a[j][1]){
                c[i][j] = -1;
                c[j][i] = 1;
            }
        }
    }
    if(c[0][2] + c[0][3] == 2 || c[1][2] + c[1][3] == 2){
        cout << "Team 1" << endl;
        return 0;
    }

    if(max(c[2][0], c[3][0]) == 1 && max(c[2][1], c[3][1]) == 1){
        cout << "Team 2" << endl;
        return 0;
    }
    cout << "Draw" << endl;
    return 0;
}