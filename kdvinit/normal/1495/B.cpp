/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int mx = 0;
int freq = 0;
int ind = 0;

void maximise(int val, int i)
{
    if(val==mx) freq++;
    if(val>mx)
    {
        mx = val;
        ind = i;
        freq = 1;
    }
}

void solve()
{
    int n;
    cin>>n;

    int p[n+2];
    p[0]=0;
    p[n+1]=0;
    for(int i=1;i<=n;i++) cin>>p[i];

    int maxima[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(p[i]>p[i-1] && p[i]>p[i+1]) maxima[i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        if(maxima[i]==0) continue;

        int j=i;
        while(j<n && p[j]>p[j+1]) j++;
        int diff = j-i+1;
        maximise(diff, i);

        j = i;
        while(j>1 && p[j]>p[j-1]) j--;
        diff = i-j+1;
        maximise(diff, i);
    }

    //cout<<ind<<" "<<mx<<" "<<freq<<endl;

    if(freq!=2) { cout<<0<<endl; return; }

    int j = ind;
    while(j<n && p[j]>p[j+1]) j++;
    //cout<<ind<<" "<<j<<endl;
    int mx1 = j-ind+1;

    j = ind;
    while(j>1 && p[j]>p[j-1]) j--;
    int mx2 = ind-j+1;

    //cout<<mx1<<" "<<mx2<<endl;

    if(mx1==mx2 && mx%2==1) cout<<1<<endl;
    else cout<<0<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}