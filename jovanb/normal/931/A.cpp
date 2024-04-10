#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int a, b;
    cin >> a >> b;
    if(a == b) {cout << 0; return 0;}
    if(a > b) swap(a,b);
    int c = (a+b)/2;
    int movea = ((c-a)*(c-a+1))/2;
    int moveb = ((b-c)*(b-c+1))/2;
    cout << movea+moveb;
    return 0;
}