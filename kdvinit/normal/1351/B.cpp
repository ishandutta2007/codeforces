#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        if(max(a1,b1)==max(a2,b2) && min(a1,b1)+min(a2,b2)==max(a2,b2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}