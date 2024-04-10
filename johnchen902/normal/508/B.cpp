#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
        if(s[i] % 2 == 0 && s[i] < s[n - 1]) {
            swap(s[i], s[n - 1]);
            cout << s << endl;
            return 0;
        }
    for(int i = n - 1; i >= 0; i--)
        if(s[i] % 2 == 0 && s[i] > s[n - 1]) {
            swap(s[i], s[n - 1]);
            cout << s << endl;
            return 0;
        }
    cout << "-1" << endl;
    return 0;
}