#include <iostream>
#include <stack>
using namespace std;

stack <int> S;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sol  =  n;
    for( int i=0; i<n; i++ ) {
        if( S.empty() ) S.push(i);
        else if( s[S.top()] != s[i] ) {
            sol -= 2;
            S.pop();
        }else S.push(i);
    }
    cout << sol;
    return 0;
}