#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define x first
#define y second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long t,n,x[100005],y[100005],z[100005],i,d;
pair < long , pll > ans;
long check(long mid)
{
    long i,v[4][2],a,b,c;
    for(i=0;i<4;++i)
    v[i][0]=LLONG_MIN,v[i][1]=LLONG_MAX;
    for(i=0;i<n;++i)
    {
        v[0][0]=max(v[0][0],x[i]+y[i]+z[i]-mid);
        v[0][1]=min(v[0][1],x[i]+y[i]+z[i]+mid);
        v[1][0]=max(v[1][0],-x[i]+y[i]+z[i]-mid);
        v[1][1]=min(v[1][1],-x[i]+y[i]+z[i]+mid);
        v[2][0]=max(v[2][0],x[i]-y[i]+z[i]-mid);
        v[2][1]=min(v[2][1],x[i]-y[i]+z[i]+mid);
        v[3][0]=max(v[3][0],x[i]+y[i]-z[i]-mid);
        v[3][1]=min(v[3][1],x[i]+y[i]-z[i]+mid);
    }
    for(i=0;i<4;i++)
    if(v[i][0]>v[i][1]) return 0;
    // even
    if((v[1][0]+abs(v[1][0]%2)+v[2][0]+abs(v[2][0]%2)<=v[0][1]-v[3][0]-abs(v[3][0]%2)) && (v[1][1]-abs(v[1][1]%2)+v[2][1]-abs(v[2][1]%2))>=v[0][0]-v[3][1]+abs(v[3][1]%2))
    {
        if(v[1][0]+abs(v[1][0]%2)+v[2][0]+abs(v[2][0]%2)>=v[0][0]-v[3][0]-abs(v[3][0]%2))
        a=v[1][0]+abs(v[1][0]%2),b=v[2][0]+abs(v[2][0]%2),c=v[3][0]+abs(v[3][0]%2);
        else if(v[1][1]-abs(v[1][1]%2)+v[2][1]-abs(v[2][1]%2)<=v[0][1]-v[3][1]+abs(v[3][1]%2))
        a=v[1][1]-abs(v[1][1]%2),b=v[2][1]-abs(v[2][1]%2),c=v[3][1]-abs(v[3][1]%2);
        else
        {
            a=v[1][0]+abs(v[1][0]%2),b=v[2][0]+abs(v[2][0]%2),c=v[3][0]+abs(v[3][0]%2);
            if(a+b<v[0][0]-v[3][1]+abs(v[3][1]%2))
            {
                c=v[3][1]-abs(v[3][1]%2);
                if(a+c<v[0][0]-v[2][1]+abs(v[2][1]%2))
                {
                    b=v[2][1]-abs(v[2][1]%2);
                    a=min(v[1][1]-abs(v[1][1]%2),v[0][1]-abs(v[0][1]%2)-b-c);
                }
                else b=min(v[2][1]-abs(v[2][1]%2),v[0][1]-abs(v[0][1]%2)-a-c);
            }
            else c=min(v[3][1]-abs(v[3][1]%2),v[0][1]-abs(v[0][1]%2)-a-b);
        }
        if(v[0][0]<=a+b+c && a+b+c<=v[0][1] && v[1][0]<=a && a<=v[1][1] && v[2][0]<=b && b<=v[2][1] && v[3][0]<=c && c<=v[3][1])
        {
            ans={(b+c)/2,{(a+c)/2,(a+b)/2}};
            return 1;
        }
    }
    // odd
    if((v[1][0]+!abs(v[1][0]%2)+v[2][0]+!abs(v[2][0]%2)<=v[0][1]-v[3][0]-!abs(v[3][0]%2)) && (v[1][1]-!abs(v[1][1]%2)+v[2][1]-!abs(v[2][1]%2))>=v[0][0]-v[3][1]+!abs(v[3][1]%2))
    {
        if(v[1][0]+!abs(v[1][0]%2)+v[2][0]+!abs(v[2][0]%2)>=v[0][0]-v[3][0]-!abs(v[3][0]%2))
        a=v[1][0]+!abs(v[1][0]%2),b=v[2][0]+!abs(v[2][0]%2),c=v[3][0]+!abs(v[3][0]%2);
        else if(v[1][1]-!abs(v[1][1]%2)+v[2][1]-!abs(v[2][1]%2)<=v[0][1]-v[3][1]+!abs(v[3][1]%2))
        a=v[1][1]-!abs(v[1][1]%2),b=v[2][1]-!abs(v[2][1]%2),c=v[3][1]-!abs(v[3][1]%2);
        else
        {
            a=v[1][0]+!abs(v[1][0]%2),b=v[2][0]+!abs(v[2][0]%2),c=v[3][0]+!abs(v[3][0]%2);
            if(a+b<v[0][0]-v[3][1]+!abs(v[3][1]%2))
            {
                c=v[3][1]-!abs(v[3][1]%2);
                if(a+c<v[0][0]-v[2][1]+!abs(v[2][1]%2))
                {
                    b=v[2][1]-!abs(v[2][1]%2);
                    a=min(v[1][1]-!abs(v[1][1]%2),v[0][1]-!abs(v[0][1]%2)-b-c);
                }
                else b=min(v[2][1]-!abs(v[2][1]%2),v[0][1]-!abs(v[0][1]%2)-a-c);
            }
            else c=min(v[3][1]-!abs(v[3][1]%2),v[0][1]-!abs(v[0][1]%2)-a-b);
        }
        if(v[0][0]<=a+b+c && a+b+c<=v[0][1] && v[1][0]<=a && a<=v[1][1] && v[2][0]<=b && b<=v[2][1] && v[3][0]<=c && c<=v[3][1])
        {
            ans={(b+c)/2,{(a+c)/2,(a+b)/2}};
            return 1;
        }
    }
    return 0;
}
int main()
{
    io
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;++i)
        cin>>x[i]>>y[i]>>z[i];
        long lo=-1,hi=3e18,mid;
        hi++;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if(check(mid))
            hi=mid;
            else lo=mid;
        }
        if(check(lo)) d=lo;
        else if(check(mid)) d=mid;
        else if(check(hi)) d=hi;
        cout<<ans.x<<" "<<ans.y.x<<" "<<ans.y.y<<endl;
    }
    return 0;
}