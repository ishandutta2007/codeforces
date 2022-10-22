#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    char c;
    n*=m;
    for(m=0;m<n;m++){
        cin>>c;
        if(c=='C' || c=='M' || c=='Y'){cout<<"#Color";return 0;}
        
    }
cout<<"#Black&White";
    return 0;
}