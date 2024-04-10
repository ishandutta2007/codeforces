#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],safe[100005],ans;

int main()
{
    int i;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=0;i<n;i++) {
        if(i==0 || i==n-1) safe[i]=0;
        else {
            if(a[i]<=a[i-1] && a[i]<=a[i+1]) safe[i]=a[i]-1;
            else {
                safe[i]=min(a[i-1],a[i+1]);
            }
        }
    }
    for(i=1;i<n;i++) {
        safe[i]=min(safe[i],safe[i-1]+1);
    }
    for(i=n-2;i>=0;i--) {
        safe[i]=min(safe[i],safe[i+1]+1);
    }
    for(i=0;i<n;i++) {
        ans=max(ans,safe[i]);
    }
    cout<<ans+1;
}