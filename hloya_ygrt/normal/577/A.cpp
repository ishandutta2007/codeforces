#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{

    long long x,n,s=0;
    cin>>n>>x;
    if(x>n*n){ cout<<0;return 0;}else{
    if (x==1){cout<<1; } else{
        for (int i=1;i<=sqrt(x)+1;i++){
            if (x%i==0&&x/i<=sqrt(x)+1&&x/i<=n) s++; else
            if (x%i==0&&i<=n&&x/i<=n) {s+=2;}

        }
    cout<<s;}}
    return 0;
}