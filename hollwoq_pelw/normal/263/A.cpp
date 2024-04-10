#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int m;
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 5; j ++){
            cin >> m;
            if (m == 1){
                cout << abs(i-2) + abs(j-2);
                return 0;
            }
        }
    }
    return 0;
}