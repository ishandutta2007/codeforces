#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        n--;
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        int res;
        if (a[0]+a[1] > a[2]) res = (a[0]+a[1]+a[2])/2;
        else res = a[0]+a[1];
        cout << res << endl;
    }
    return 0;
}