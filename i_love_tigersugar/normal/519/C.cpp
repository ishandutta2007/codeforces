#include<bits/stdc++.h>
using namespace std;
int main(void) {
    int a,b;
    cin>>a>>b;
    if (a<b) swap(a,b);
    if (a>2*b) cout<<b; else cout<<(a+b)/3;
    cout<<endl;
    return 0;
}