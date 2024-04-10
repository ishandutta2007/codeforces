#include <bits/stdc++.h>
using namespace std;

int p;

bool nedeljiv(int x){
    for(int i=2; i*i<=x && i<=p; i++){
        if(x%i == 0)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int y, br=0;
    cin >> p >> y;
    for(int x=y; x>p; x--){
        if(br == 1000) break;
        br++;
        if(nedeljiv(x)){cout << x; return 0;}
    }
    cout << -1;
    return 0;
}