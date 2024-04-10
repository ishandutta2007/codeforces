#include <iostream>
#define DMAX 3000
using namespace std;

int n, v[DMAX], a;

int main()
{
cin>>n;

    int N=1<<n;
    N*=2;
    N--;

    for(int i=2;i<=N;i++)
    {
        cin>>a;
        v[i]=a;
    }
    int ans=0;
    N+=1;
    while(N!=2)
    {
    N=N/2;
    for(int i=N;i<2*N;i+=2)
    {
        int Max=max(v[i],v[i+1]);
        int Min=min(v[i],v[i+1]);

        ans+=Max-Min;
        v[i]=Max;
        v[i+1]=Max;
        v[i/2]+=Max;
    }
    }

    cout<<ans<<'\n';
        return 0;
}