#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, best=0, child, lastchild;
    cin >> n >> m;
    for(int a=1; a<=n; a++) {
        cin >> child;
        child--;
        if(child/m>=best) {
            best=child/m;
            lastchild=a;
        }
    }
    cout << lastchild;
}