#include <iostream>

using namespace std;

int main()
{
    long n,i;
    long long x,zbir=0,a;
    cin>>n>>x;
    for(i=0;i<n;i++){
        cin>>a;
        zbir+=a;
    }
    if(zbir+n-1==x)cout<<"YES";
    else cout<<"NO";
    return 0;
}