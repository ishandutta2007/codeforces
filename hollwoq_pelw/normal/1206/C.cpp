#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n%2==0) {
        cout << "NO";
        return 0;
    }
    int a[2*n];
    for (int i = 0; i < n; i++){
        a[i] = 2*i+1;
        a[n+i] = 2*i+2;
        if (i%2){
            a[i] = 2*i+2;
            a[n+i] = 2*i+1;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < 2*n; i++){
        cout << a[i] << ' ';
    }
    
}