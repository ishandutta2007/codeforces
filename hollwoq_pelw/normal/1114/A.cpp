#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y,z;
    cin >> x >> y >> z >> a >> b >> c;
    string s = (a >= x && a+b >= x+y && a+b+c >= x+y+z) ? "YES": "NO";
    cout << s;
}