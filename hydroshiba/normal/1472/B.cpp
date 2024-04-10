#include <bits/stdc++.h>
using namespace std;

void king_crimson(){
    int n;
    cin >> n;

    int one = 0, two = 0;
    for(int i = 1; i <= n; ++i){
        int temp;
        cin >> temp;
        if(temp == 1) ++one;
        else ++two;
    }

    if(n % 2){
        if(one % 2 == 0 && one != 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(one % 2 == 0 && two % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int enemies;
    cin >> enemies;

    while(enemies--){
        king_crimson();
    }
}