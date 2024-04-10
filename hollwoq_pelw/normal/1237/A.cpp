#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int t = 0;
    cin >> n;
    int k;
    while(n--){
        cin >> k;
        if (k%2==0) cout << k/2 << endl;
        else{
            if (t) cout << (k+1)/2 << endl;
            else cout << (k-1)/2 << endl;
            t = !t;
        }
    }
}