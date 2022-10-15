#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>n>>m;
        if(m==1 || n==1) cout<<"YES"<<endl;
        else if(m==2 && n==2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}