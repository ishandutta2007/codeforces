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
    int n,x;
    cin>>n;

    int freq[n+2]={0},freq2[n+2]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        freq[x]++;
    }

    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0) continue;
        a.push_back(i);
    }

    int len=a.size();
    int mn=0;
    for(int i=0;i<len;i++)
    {
        mn++;
        if(i==len-1) break;
        if((a[i+1]-a[i])==2) i++;
        else if(i!=len-2 && (a[i+1]-a[i])==1 && (a[i+2]-a[i+1])==1) i+=2;
        else if((a[i+1]-a[i])==1) i++;
    }

    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0) continue;
        if(freq[i]==1)
        {
            if(freq2[i-1]==0) freq2[i-1]=1;
            else if(freq2[i]==0) freq2[i]=1;
            else freq2[i+1]=1;
        }
        else if(freq[i]==2)
        {
            if(freq2[i-1]==0) { freq2[i-1]=1; freq2[i]=1; }
            else { freq2[i]=1; freq2[i+1]=1; }
        }
        else
        {
            freq2[i-1]=1;
            freq2[i]=1;
            freq2[i+1]=1;
        }
    }

    for(int i=0;i<=n+1;i++)
    {
        mx+=freq2[i];
    }
    
    cout<<mn<<" "<<mx<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}