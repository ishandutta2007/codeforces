#include <iostream>
#include <ctype.h>
using namespace std;
bool vow(char c){
    return (c != 'y' && c != 'a' && c != 'u' && c != 'e' && c != 'o' && c != 'i');
}
int main(){
    string s,res = "";
    cin >> s;
    for (int i = 0; i < s.size(); i ++){
        s[i] = tolower(s[i]);
        if (vow(s[i])){
            res += '.';
            res += s[i];
        }
    }
    cout << res;
}