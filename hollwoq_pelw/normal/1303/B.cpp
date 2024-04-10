#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long long n,g,b;
        cin >> n >> g >> b;
        long long needg = (n+1)/2;
        long long r = needg+((needg-1)/g)*b;
        if (needg < g) r = needg;
        cout << max(r,n) << endl;
    }
    return 0;
}