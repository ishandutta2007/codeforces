#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[200009];
int bit[200009],n,t,k;
int cal(int x)
{
    int ans=0;
    while(x>0){ans+=bit[x];x-=(x&(-x));}
    return ans;
}
void add(int x)
{
    while(x<=n){bit[x]++;x+=(x&(-x));}
}
int main()
{
    memset(sum,-1,sizeof sum);
    cin>>n>>t;
    while(t--)
    {
        cin>>k;
    int l=1,r=n;
    while(r>l)
    {
        int mid=(l+r)/2;
        if(sum[mid]==-1)
        {
        cout<<"? "<<1<<" "<<mid<<endl;
        fflush(stdout);
        cin>>sum[mid];
        sum[mid]-=cal(mid);
        }
        int p=mid-sum[mid]-cal(mid);
        if(p>=k)r=mid;
        else l=mid+1;
    }
    cout<<"! "<<l<<endl;
    fflush(stdout);
    add(l);
    }
    return 0;
}