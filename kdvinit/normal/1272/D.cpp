/*
My Test Case - 
20
2 1 3 4 5 6 3 4 2 5 7 8 6 2 1 3 5 9 3 6
Mistake - make ans=1 when ans = 0;
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long int a[n];
    int cntr1=1,cntr2=1,freq[n+1],fst[n+1],lst[n+1]; // cntr1=no of freq and cntr2=val of freq;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0) continue;
        if(a[i-1]<a[i])
        {
            if(cntr2==1) fst[cntr1]=i-1;
            cntr2++;
            if(i==n-1)
            {
                freq[cntr1]=cntr2;
                lst[cntr1]=i;
                cntr1++;
            }
        }
        if(a[i-1]>=a[i])
        {
            if(cntr2==1) continue;
            freq[cntr1]=cntr2;
            lst[cntr1]=i-1;
            cntr1++;
            cntr2=1;
        }
    }
    int ans=0;
    for(int i=1;i<cntr1;i++)
    {
        if(i==cntr1-1) { ans=max(ans,freq[i]); continue; }
        if(fst[i+1]-lst[i]==1)
        {
            int x=lst[i];
            if(a[x-1]<a[x+1] || a[x]<a[x+2]) freq[i]=freq[i]+freq[i+1]-1;
        }
        ans=max(ans,freq[i]);
    }
    if(ans==0) ans=1;
    //for(int i=1;i<cntr1;i++) cout<<freq[i]<<" ";
    cout<<ans<<endl;
    return 0;
}