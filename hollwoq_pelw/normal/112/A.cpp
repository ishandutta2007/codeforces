#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    string a,b;
    char x,y;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i ++){
        x = tolower(a[i]);
        y = tolower(b[i]);
        if (x < y){
            cout << -1;
            return 0;
        }else if (x > y){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}