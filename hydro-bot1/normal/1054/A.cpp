// Hydro submission #625ceb11fa9408d417fea8e7@1650256658325
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    printf(abs(x-y)*t2+abs(x-z)*t2+3*t3>abs(x-y)*t1?"NO\n":"YES\n");
    return 0;
}