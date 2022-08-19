#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int main(){
    cin >> a >> b;
    for (auto &i : a){
        if(i == '0') i += 10;
    }
    auto t = min_element(a.begin(),a.end());
    swap(*t,a[0]);
    for (auto &i : a){
        if(i == '0' + 10) i -= 10;
    }
    sort(a.begin()+1,a.end());
    if(a == b) cout << "OK";
    else cout << "WRONG_ANSWER";
}