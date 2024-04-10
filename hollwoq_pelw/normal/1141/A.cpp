#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int s2 = 0, s3 = 0;
    while(n%2==0) {n/=2; s2 --;}
    while(n%3==0) {n/=3; s3 --;}
    while(m%2==0) {m/=2; s2 ++;}
    while(m%3==0) {m/=3; s3 ++;}
    if (s3 < 0 || s2 < 0 || n!=m) cout << -1;
    else cout << s2+s3;
    return 0;
}