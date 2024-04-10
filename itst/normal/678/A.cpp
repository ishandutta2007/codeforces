#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    cout << (int)ceil((n + 0.999) / m) * m;
    return 0;
}