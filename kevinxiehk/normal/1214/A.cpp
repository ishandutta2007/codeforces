#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    int min=99999999;
    cin>>a>>b>>c;
    c*=5;
    int now=0;
    while(now*b<=a){
        int t=a-now*b;
        int tt=t%c;
        if(tt<min)min=tt;
        now++;
    }
    cout<<min<<endl;
    return  0;
}