#include<bits/stdc++.h>
using namespace std;
inline int ceil(int a,int b) {
    return (a/b+(a%b>0));
}
int main(void) {
    int a1,a2,a3,b1,b2,b3,n;
    cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
    cout<<(ceil(a1+a2+a3,5)+ceil(b1+b2+b3,10)<=n?"YES":"NO");
    return 0;
}