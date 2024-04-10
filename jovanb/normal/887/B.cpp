#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool ima[5][10];
int u[10];

bool moze(int x, int n){
    vector <int> digits;
    while(x){
        digits.push_back(x%10);
        x /= 10;
    }
    if(digits.size() > n) return 0;
    for(int i=1; i<=n; i++) u[i] = i;
    do{
        bool moze = 1;
        for(int i=1; i<=n; i++){
            if(u[i] <= digits.size() && !ima[i][digits[u[i]-1]]) moze = 0;
        }
        if(moze) return 1;
    } while(next_permutation(u+1, u+1+n));
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            int x;
            cin >> x;
            ima[i][x] = 1;
        }
    }
    for(int i=1; ; i++){
        if(!moze(i, n)){
            cout << i-1 << "\n";
            return 0;
        }
    }
    return 0;
}