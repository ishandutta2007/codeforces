#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n,k; cin >> n;
        int c[3] = {0};
        while(n--){
            cin >> k;
            c[k%3] ++;
        }
        cout << c[0]+min(c[1],c[2])+(max(c[1],c[2])-min(c[1],c[2]))/3 << endl;
    }
}