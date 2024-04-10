#include <iostream>
#include <math.h>
#define For(i,i0,i1) for(int i=i0;i<i1;i++)

using namespace std;

int main()
{
    int n;
    int p[1000],q[1000];
    cin>>n;
    For(i,0,n){
        cin>>p[i];
        cin>>q[i];
    }
    int ans=0;
    For(i,0,n){
        if(q[i]-p[i]>=2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}