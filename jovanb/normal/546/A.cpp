#include <bits/stdc++.h>
using namespace std;
int main(){
    long long k,n,w;
    cin>>k>>n>>w;
long long a=0;
    cout<<max(a,k*((w+1)*w)/2-n);
    return 0;
}