#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int trial = *max_element(s.begin(),s.end()) - '0';
    cout << trial << endl;
    for (int i=0; i<trial; i++) {
        int j = 0;
        while (j < s.size() && s[j] == '0') {
            j++;
        }
        while (j < s.size()) {
            if(s[j] > '0') cout << 1;
            else cout << 0;
            if(s[j] != '0') s[j]--;
            j++;
        }
        cout << ' ';
    }
}