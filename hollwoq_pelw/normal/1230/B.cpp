#include <iostream>
using namespace std;
int main(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    int i = 0;
    if (n == 1 && k > 0){
        cout << "0";
        return 0;
    }
    while (i < n && k > 0){
        if (i == 0 && s[i] != '1') {s[i] = '1'; k--;}
        else if (i != 0 && s[i] != '0') {s[i] = '0'; k--;}
        i++;
    }
    cout << s;
    return 0;
}