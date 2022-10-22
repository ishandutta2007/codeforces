#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n;
    cin >> n;
    int x,y,z,a[n];
    
    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> x;
    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> y;
    cout << "? 3 1" << endl;
    fflush(stdout);
    cin >> z;
    
    int s = (x+y+z)/2;
    
    a[0] = s-y;
    a[1] = s-z;
    a[2] = s-x;
    
    for (int i = 3; i < n; i++){
        cout << "? " << i+1 << " 1" << endl;
        fflush(stdout);
        cin >> s;
        a[i] = s-a[0];
    }
    
    cout << "! ";
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}