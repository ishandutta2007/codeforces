#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
inline int revnum(int x) {
    string s;
    while (x>0) {
        s.push_back(x%10);
        x=x/10;
    }
    int ret=0;
    FORE(it,s) ret=ret*10+*it;
    return (ret);
}
int main(void) {
    int a,b;
    cin >> a >> b;
    cout << a+revnum(b);
    return 0;
}