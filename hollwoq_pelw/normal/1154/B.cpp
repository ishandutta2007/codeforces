#include <bits/stdc++.h>
using namespace std;

int main(){
    int z;
    cin >> z;
    int a[3], i = 0;
    set<int> t;
    while(z--){
        int x;
        cin >> x;
        if (!t.count(x)){
            if(i >= 3) return cout << -1, 0;
            a[i++] = x;
        }
        t.insert(x);
    }
    sort(a,a+i);
    if (i == 1) return cout << 0, 0;
    int n = a[i-1]-a[0];
    if (n%2==0) n/=2;
    else{
        if (i == 3) return cout << -1, 0;
        else return cout << n, 0;
    }
    if (i == 2 || (i == 3 && 2*a[1] == a[2]+a[0])) return cout << n, 0;
    return cout << -1, 0;
}