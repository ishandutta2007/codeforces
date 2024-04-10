/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int x[n+1],y[m+1],temp,sum=0,res=0,m1,m2,cnt=0;
    for(int i=1;i<=n;i++) cin>>x[i];

    sort(x+1,x+n+1);
    int freq[m+1]={0},freq2[m+1]={0};
    freq[m]+=2;
    for(int i=2;i<=n;i++)
    {
        temp=x[i]-x[i-1];
        if(temp>m) temp=m+1;
        temp--;
        m1=(temp/2);
        m2=((temp+1)/2);
        freq[m1]++;
        freq[m2]++;
    }
    for(int i=m;i>0;i--)
    {
        sum+=freq[i];
        freq[i]=sum;
    }

    temp=m;
    for(int i=1;i<=m;i++)
    {
        if(freq[i]>=temp)
        {
            res+=(temp)*i;
            freq2[i]=temp;
            break;
        }
        else
        {
            res+=(freq[i])*i;
            temp-=freq[i];
            freq2[i]=freq[i];
        }
    }

    cout<<res<<endl;

    for(int i=2;i<=n;i++)
    {
        temp=x[i]-x[i-1];
        if(temp>m) temp=m+1;
        temp--;
        m1=(temp/2);
        m2=((temp+1)/2);
        for(int j=1;j<=m1;j++)
        {
            if(freq2[j]==0) break;
            y[++cnt]=x[i-1]+j;
            freq2[j]--;
        }
        for(int j=1;j<=m2;j++)
        {
            if(freq2[j]==0) break;
            y[++cnt]=x[i]-j;
            freq2[j]--;
        }
    }

    int i=1;
    while(1)
    {
        if(i>m) break;
        if(freq2[i]==0) break;
        freq2[i]--;
        y[++cnt]=x[1]-i;
        i++;
    }
    i=1;
    while(1)
    {
        if(i>m) break;
        if(freq2[i]==0) break;
        freq2[i]--;
        y[++cnt]=x[n]+i;
        i++;
    }

    sort(y+1,y+cnt+1);
    for(int ii=1;ii<=cnt;ii++) cout<<y[ii]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}