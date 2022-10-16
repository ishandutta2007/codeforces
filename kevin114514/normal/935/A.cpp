#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,ans=0;
    cin>>N;
    for(int i=1;i<N;i++)
        if(N%i==0)
            ans++;
    cout<<ans<<endl;
    return 0;
}