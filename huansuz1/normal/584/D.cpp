#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;

 long long n,m,q,k,a[1234],b[1234],c[1234],x,y,ma,p;


 int main(){
 cin>>n;
 p=0;

 for (int i=2; i*i<=n; i++)
    if (n%i==0){ p=1; break;}
 if (p==0) {
    cout<<1<<endl;
    cout<<n;
    return 0;
 }
 n-=2;
 p=0;

 for (int i=2; i*i<=n; i++)
    if (n%i==0){ p=1; break;}
 if (p==0) {
    cout<<2<<endl;
    cout<<n<<" "<<2;
    return 0;
 }
 n-=2;
 p=0;

 for (int i=2; i*i<=n; i++)
    if (n%i==0){ p=1; break;}
 if (p==0) {
    cout<<3<<endl;
    cout<<n<<" "<<2<<" "<<2;
    return 0;
 }
 n++;
 p=0;

 for (int i=2; i*i<=n; i++)
    if (n%i==0){ p=1; break;}
 if (p==0) {
    cout<<2<<endl;
    cout<<n<<" "<<3;
    return 0;
 }
 n+=3;
 cout<<3<<endl<<3<<" ";
    
 for (int i=5; i<n; i+=2){
    x=0;
    for (int j=2; j*j<=i; j++)
        if (i%j==0) {x=1; break;}
    if (x==0) {
        p=0;
        for (int j=2; j*j<=(n-i-3); j++)
            if ((n-i-3)%j==0) {p=1; break;}
        if (p==0) {cout<<i<<" "<<n-i-3; return 0;}
    
    }
 }  
    
    
    
    
    return 0;
 }