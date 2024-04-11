#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

bool checked[1200][1200];
bool field[1200][1200];

void edit(int i, int j){
    int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dj[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int index = 0; index < 8; index++){
        int newi = i + di[index];
        int newj = j + dj[index];
        if(!field[newi][newj]){
            return;
        }
    }
    for(int index = 0; index < 8; index++){
        int newi = i + di[index];
        int newj = j + dj[index];
        checked[newi][newj] = true;
    }
}

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    string s[1200];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1][j - 1] == '#'){
                field[i][j] = true;
            } else {
                field[i][j] = false;
            }
            checked[i][j] = false;
        }
    }
    for(int i = 2; i < n; i++){
        for(int j = 2; j < m; j++){
            edit(i, j);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(field[i][j] && (!checked[i][j])){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}