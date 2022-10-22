#include <iostream>
using namespace std;
bool d(string s, int i){
    char k = s[i];
    for (int j = i+1; j < i+7; j++){
        if (k != s[j]){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    if (s.size() < 7){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < s.size()-6; i ++){
        if (d(s,i)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}