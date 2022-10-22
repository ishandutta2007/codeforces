#include <iostream>
using namespace std;
int main(){
    string s,k="hello";
    cin >> s;
    int j = 0;
    //delete same letters
    for (int i = 0; i < s.size(); i++){
        if (j < 5 && s[i] == k[j]) j ++;
    }
    if (j == 5) cout << "YES";
    else cout << "NO";
    return 0;
}