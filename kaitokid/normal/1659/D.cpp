#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bit[200009],n;
int a[200009],ans[200009];
ll sum;
int cal(int x)
{
    int res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));
    }
    return res;
}
void add(int x)
{
    while(x<=n)
    {
        bit[x]++;
        x+=(x&(-x));
    }
}
bool ch(int x,int y)
{
    int u=cal(y)+sum;
    return u>=(y-x+1);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){cin>>a[i];sum+=a[i];bit[i]=0;}
        sum/=n;
        for(int i=n;i>1;i--)
        {
         if(sum==0){ans[i]=0;continue;}
         int l=i,r=n;
         while(r>l)
         {
             int mid=(l+r+1)/2;
             if(ch(i,mid))l=mid;
             else r=mid-1;

         }
        int u=l-i+1;
        if(a[i]>u){ans[i]=1;add(i);sum--;}
        else ans[i]=0;
        }
        ans[1]=sum;

        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}