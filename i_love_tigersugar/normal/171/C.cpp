#include<bits/stdc++.h>
using namespace std;
int main(void) {
    long long tmp,res=0;
    int id=0;
    while (cin >> tmp) res+=tmp*id++;
    cout << res;
    return 0;
}