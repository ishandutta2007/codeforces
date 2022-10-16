#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    char field[51][51];
    for(int i = 1; i <= 50; i++){
        for(int j = 1; j <= 50 ; j++){
            field[i][j] = 'A';
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flag = true;
    if(a > b){
        flag = false;
        swap(a, b);
    }
    int x = 2;
    int y = 2;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    if(a != 1){
        for(int k = 0; k < 8; k++){
            field[x + dx[k]][y + dy[k]] = 'C';
        }
        c--;
        for(int i = 2; i < a; i++){
            b--;
            x += 4;
            if(x > 49){
                x = 2;
                y += 4;
            }
            for(int k = 0; k < 8; k++){
                field[x + dx[k]][y + dy[k]] = 'B';
            }
        }
    }
    x = 51;
    y = 49;
    for(int i = 0; i < b; i++){
        x -= 2;
        if(x < 1){
            x = 49;
            y -= 2;
        }
        field[x][y] = 'B';
    }
    for(int i = 0; i < c; i++){
        x -= 2;
        if(x < 1){
            x = 49;
            y -= 2;
        }
        field[x][y] = 'C';
    }
    for(int i = 0; i < d; i++){
        x -= 2;
        if(x < 1){
            x = 49;
            y -= 2;
        }
        if(field[x][y] != 'A'){
            i--;
            continue;
        }
        field[x][y] = 'D';
    }
    cout << "50 50" << endl;
    for(int i = 1; i <= 50; i++){
        for(int j = 1; j <= 50; j++){
            if(!flag){
                if(field[i][j] == 'A'){
                    field[i][j] = 'B';
                } else if(field[i][j] == 'B'){
                    field[i][j] = 'A';
                }
            }
            cout << field[i][j];
        }
        cout << endl;
    }
    return 0;
}