#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    vector<vector<int>> v = {
        {
            {1, 1, 1, 0, 1, 1, 1},
            {0, 0, 1, 0, 0, 1, 0},
            {1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 0, 1, 1},
            {0, 1, 1, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 1, 1},
            {1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 0, 0, 1, 0},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1}
        }
    };
    int n;
    cin >> n;
    int x = n / 10;
    int y = n % 10;
    int a = 0, b = 0;
    for(int i = 0; i < 10; ++i){
        bool bo = 1;
        for(int o = 0; o < 7; ++o){
            if(v[x][o] > v[i][o]){
                bo = 0;
                break;
            }
        }
        if(bo){
            ++a;
        }
    }
    for(int i = 0; i < 10; ++i){
        bool bo = 1;
        for(int o = 0; o < 7; ++o){
            if(v[y][o] > v[i][o]){
                bo = 0;
                break;
            }
        }
        if(bo){
            ++b;
        }
    }
    cout << a * b << endl;

}