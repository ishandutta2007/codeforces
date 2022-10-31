#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solve(){
    string s;
    cin >> s;
    if(!equal(s.begin(), s.end(), s.rbegin()))
        return false;
    if(s.find_first_not_of("WTYUIOHAXVM") != string::npos)
        return false;
    return true;
}

int main(){
    cout << (solve() ? "YES" : "NO") << endl;
}