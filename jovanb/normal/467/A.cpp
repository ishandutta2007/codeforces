#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i,br=0,a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        if(a+2<=b)br++;
    }
    cout<<br;
}