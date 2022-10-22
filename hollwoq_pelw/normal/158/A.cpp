#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n], res = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i < k && a[i] > 0) res ++;
    }
    if (res != k){ 
        cout << res; 
        return 0;
    }
    int t = a[k-1];
    for (int i = k; i < n; i++){
        if (a[i] == t) res ++;
        else break;
    }
    cout << res;
}