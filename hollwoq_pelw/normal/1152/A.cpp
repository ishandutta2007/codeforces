#include <bits/stdc++.h>
using namespace std;

int n,m,c1[2],c2[2],x;
int main(){
    cin >> n >> m;
    while(n--) {cin >> x; c1[x%2]++;}
    while(m--) {cin >> x; c2[x%2]++;}
    cout << min(c1[1],c2[0])+min(c1[0],c2[1]);
    return 0;
}