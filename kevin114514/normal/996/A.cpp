#include<bits/stdc++.h>
using namespace std;
int X[5]={100,20,10,5,1},ans;
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<5;i++)
    {
        ans+=N/X[i];
        N%=X[i];
    }
    cout<<ans<<endl;
}