#include <iostream>
#include<algorithm>

using namespace std;

long long n,k,ans,f;
bool mark[10],mark2;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        mark2=false;
        for(int i=0;i<10;i++)
            mark[i]=false;
        f=0;
        while(a>0)
        {
            int b=a%10;
            mark[b]=true;
            f++;
            a=a/10;
        }
        for(int i=0;i<=k;i++)
            if(mark[i]==false)
                mark2=true;
        if(mark2==false)
            ans++;
    }
    cout<<ans<<endl;
}