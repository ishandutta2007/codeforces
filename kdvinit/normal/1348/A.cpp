#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<pow(2,(n/2)+1)-2<<endl;
    }
    return 0;
}