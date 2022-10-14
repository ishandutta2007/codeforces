#include<iostream>

using namespace std;

int n, d;
int cnt, sol;
string s, ss;

int main () {
    cin >> n >> d;
    for (int i=0; i<n; i++) ss+='1';
    for (int i=0; i<d; i++) {
        cin >> s;
        if (s!=ss) {
            cnt++;
            sol=max(sol, cnt);
        } else {
            cnt=0;
        }
    }
    cout << sol;
    return 0;
}