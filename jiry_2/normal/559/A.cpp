#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c;
int calc(int k){
    return k*k;
}
int main(){
    int k1,k2,k3,k4,k5,k6;
    cin>>k1>>k2>>k3>>k4>>k5>>k6;
    cout<<calc(k1+k2+k6)-calc(k2)-calc(k4)-calc(k6)<<endl;
}