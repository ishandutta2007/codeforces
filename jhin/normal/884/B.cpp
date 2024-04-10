#include <iostream>
#include <algorithm>

using namespace std;
int n,x,c,a;
int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>a,c+=a;
    if(x+1-n==c)cout<<"YES";else cout<<"NO";
    return 0;
}