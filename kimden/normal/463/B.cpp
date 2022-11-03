#include <iostream>

using namespace std;

int main()
{
    int n,i,max;
    int h[100000];
    cin>>n;
    max=0;
    for(i=0;i<n;i++){
        cin>>h[i];
        if(max<h[i])max=h[i];
    }
    cout<<max;
    return 0;
}