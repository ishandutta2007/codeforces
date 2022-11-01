#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,x[100000];
    cin>>n;
    for (int i=0;i<n;i++){
            cin>>x[i];
    }
    int first=x[0];
    int last=x[n-1];
    int thismin=0,thismax=0;
    cout<<x[1]-x[0]<<" "<<last-x[0]<<endl;
    for (int i=1;i<n-1;i++){
        thismin=min(x[i]-x[i-1],x[i+1]-x[i]);
        thismax=max(x[i]-first,last-x[i]);
        cout<<thismin<<" "<<thismax<<endl;
    }
    cout<<x[n-1]-x[n-2]<<" "<<x[n-1]-first<<endl;


    return 0;
}