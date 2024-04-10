#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int ans=0;
    int tmp=0;
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        tmp-=a;
        tmp+=b;
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}