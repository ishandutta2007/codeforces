#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> s;
    s.insert(n);
    while(true){
        n ++;
        while(n%10==0) {n/=10;}
        if (n == 1 && s.count(1)) break;
        s.insert(n);
    }
    cout << s.size();
    return 0;
}