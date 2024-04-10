#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        n--;
        long c,s;
        cin >> c >> s;
        long v = s/c;
        long t = s%c;
        long cost = t*(v+1)*(v+1)+(c-t)*v*v;
        cout << cost << endl;
    }
    return 0;
}