#include <bits/stdc++.h>
using namespace std;

void prnt(int k, char c){
    for(int i=1; i<=k; i++) cout << c;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, r, b;
        cin >> n >> r >> b;
        int k = r/(b+1);
        int d = r%(b+1);
        int h = (b+1) - d;
        if(d){
            prnt(k + 1, 'R');
            d--;
        }
        else{
            prnt(k, 'R');
            h--;
        }
        while(d--){
            prnt(1, 'B');
            prnt(k + 1, 'R');
        }
        while(h--){
            prnt(1, 'B');
            prnt(k, 'R');
        }
        cout << "\n";
    }
    return 0;
}