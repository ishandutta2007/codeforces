#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long n,m,a,b;
int main(){
    cin>>n>>m>>a>>b;
    n%=m;
    cout<<min(b*n,a*(m-n));
}