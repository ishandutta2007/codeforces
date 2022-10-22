#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int m,a,b,c,n;
        cin >> a >> b >> c >> n;
        m = a;
        if (m<b) m = b;
        if (m<c) m = c;
        if ((a+b+c+n)%3==0 && (a+b+c+n >= 3*m)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
    }
    return 0;
}