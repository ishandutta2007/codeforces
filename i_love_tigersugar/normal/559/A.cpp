#include<bits/stdc++.h>
#define SQR(x) (1LL*(x)*(x))
using namespace std;
int main(void) {
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<SQR(b+a+f)-SQR(b)-SQR(d)-SQR(f)<<endl;
    return 0;
}