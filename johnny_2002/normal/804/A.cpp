#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=5e3+10;

int solve(int n){
    if (n<=2) return 0;
    if (n%2==0) return n/2-1;
    return n/2;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}