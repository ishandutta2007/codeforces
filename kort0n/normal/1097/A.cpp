#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string table;
    string hand[5];
    cin >> table;
    for(int i = 0; i < 5; i++){
        cin >> hand[i];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            if(table[i] == hand[j][i]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}