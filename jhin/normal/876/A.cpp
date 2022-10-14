#include <iostream>
#include <algorithm>

using namespace std;
int n,a[3],r[2],o[2],e[2],c,x=1;
int main()
{
    cin>>n;n--;
    for(int i=0;i<3;i++) cin>>a[i];
    while(n){if(n!=0&&x==1){if(a[0]<=a[1]){n--;x=2;c+=a[0];}else {n--;x=3;c+=a[1];}}
    if(n!=0&&x==2){if(a[0]<=a[2]){n--;x=1;c+=a[0];}else {n--;x=3;c+=a[2];}}
    if(n!=0&&x==3){if(a[1]<=a[2]){n--;x=1;c+=a[1];}else {n--;x=2;c+=a[2];}}}

    cout<<c;
    return 0;
}