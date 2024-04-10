#include <iostream>
#include<algorithm>

using namespace std;

const int MAXN=200000;
long long n,m,a[MAXN],b[MAXN],ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i]>>b[i];
    for(int i=0;i<m;i++)
    {
        if(i!=0 && abs(b[i]-b[i-1])>a[i]-a[i-1])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        if(i==0)
            ans=b[0]+a[0]-1;
        else
            ans=max(ans,(a[i]-a[i-1]-abs(b[i]-b[i-1]))/2+max(b[i],b[i-1]));
    }
    ans=max(ans,b[m-1]+n-a[m-1]);
    cout<<ans<<endl;
}