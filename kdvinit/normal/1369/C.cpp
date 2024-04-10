#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);

        int w[k]={0};
        for(int i=0;i<k;i++) cin>>w[i];
        sort(w,w+k);

        int mohit=0,strtI,endI=n-1,cntr=k;
        long long int sum=0;
        for(int v=0;v<k;v++)
        {
            int m=w[v];

            if(m==1)
            {
                sum+=(2*a[endI]);
                endI--;
                cntr--;
                continue;
            }

            if(m==2)
            {
                sum+=a[endI]+a[endI-1];
                endI-=2;
                cntr--;
                continue;
            }

            mohit++;
            if(mohit==1) strtI=endI-cntr;

            strtI-=(m-2);
            sum+= a[endI] + a[strtI];
            endI--;
            strtI--;
        }
        cout<<sum<<endl;
    }
}