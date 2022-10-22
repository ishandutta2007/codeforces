#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int w = min(a[0]/3, min(a[1],a[2])/2);
    a[0] -= w*3;
    a[1] -= w*2;
    a[2] -= w*2;
    int x[] = {0,1,2,0,2,1,0}, d=0;
    for (int i = 0; i < 7; i++){
        int b[3] = {a[0],a[1],a[2]};
        int cur = 0;
        while(b[x[(i+cur++)%7]]--){}
        d = max(d,cur-1);
    }
    cout << w*7+d;
    
}