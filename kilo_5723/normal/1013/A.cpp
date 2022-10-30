#include<iostream>
using namespace std;
int main()
{
    int i,n,t,tota=0,totb=0;
    cin>>n;
    for (i=0;i<n;i++){
        cin>>t;
        tota+=t;
    }
    for (i=0;i<n;i++){
        cin>>t;
        totb+=t;
    }
    if (tota<totb)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}