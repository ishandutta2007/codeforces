#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a[3],n;
        cin >> a[0] >> a[1] >> n;
        a[2] = a[1]^a[0];
        cout << a[n%3] << endl;
    }
    return 0;
}