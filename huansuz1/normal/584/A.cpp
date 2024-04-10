#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;

 int n,m,q,k,a[1234],b[1234],c[1234],x,y,ma,p;


 int main(){
 cin>>n>>m;
 if (n==1 && m<10) {cout<<m;return 0;} else 
 if (n==1 && m==10) {cout<<-1; return 0;}
 if (m<10){
 for (int i=1; i<=n; i++) 
    cout<<m;} else {
        cout<<1;
        for (int i=0; i<n-1; i++)
            cout<<0;
    
    }
    
    
    
    
    
    return 0;
 }