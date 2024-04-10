#include <bits/stdc++.h>
using namespace std;
int main(){
    int m=0,c=0,n,a,b;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        c += b-a;
        if (c > m){
            m = c;
        }
    }
    cout << m;
}