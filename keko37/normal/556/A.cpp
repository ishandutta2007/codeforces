#include<iostream>

using namespace std;

int n, sol;
char c;

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c-'0') sol++; else sol--;
    }
    if (sol<0) sol*=-1;
    cout << sol;
    return 0;
}