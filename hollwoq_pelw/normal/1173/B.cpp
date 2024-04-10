#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int s = n/2+1;
    cout << s << endl;
    int x=1,y=1;
    while(n--){
        cout << x << ' ' << y << endl;
        if (x < s) x++;
        else y ++;
    }
    return 0;
}