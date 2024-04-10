#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    int x = 0, n;
    string s;
    cin >> n;
    while (n){
        n --;
        cin >> s;
        if (s == "--X" || s == "X--"){
            x --;
        }
        if (s == "++X" || s == "X++"){
            x ++;
        }
    }
    cout << x;
}