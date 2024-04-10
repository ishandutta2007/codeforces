#include <iostream>
using namespace std;
long long binpow (long long k,int h){
    if(h==1)
    return k;
    long long u=binpow(k,h/2);
    if(h%2){
        return u*u*k;
    }else{
        return u*u;
    }
}
int main()
{
    int n;
    long long p=1;
    cin >> n;
    p = binpow(2,n+1)-2;
    cout << p;
    return 0;
}