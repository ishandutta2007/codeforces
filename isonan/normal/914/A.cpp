#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

long long a,b=-10000000,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
long long A[1001];
int main(){
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>A[i];
        int x=sqrt(A[i]);
        if(x*x!=A[i]||A[i]<0)b=max(b,A[i]);
    }
    cout<<b;
}