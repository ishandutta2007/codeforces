#include<iostream>
using namespace std;

long long int gcd(long long int a, long long int b){
    long long int t;
    while(b!=0){
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main(){
    long long int n;
    int t;    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<1+(4*n*(n+1))/(gcd(4*n,n+1)*(n+1))<<endl;
    }
    return 0;
}