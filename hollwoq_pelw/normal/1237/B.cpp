#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> checked;
    int a[n],b[n];
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];
    int c = 0, id2 = 0, id1 = 0;
    while(id2 < n){
        while(checked.count(a[id1])){
            id1 ++;
        }
        if (b[id2]!=a[id1]) c++;
        checked.insert(b[id2]);
        id2 ++;
    }
    cout << c;
}