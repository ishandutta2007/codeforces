#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        long long int n=a.size(),cnt1=0,cnt2=0,cnt3=0,temp1=2*n,temp2=2*n,temp3=2*n,mn1[n],mn2[n],mn3[n],ans=n;
        for(long long int i=n-1;i>=0;i--)
        {
            if(a[i]=='1') {cnt1++; temp1=i;}
            else if(a[i]=='2') {cnt2++; temp2=i;}
            else {cnt3++; temp3=i;}
            mn1[i]=temp1;
            mn2[i]=temp2;
            mn3[i]=temp3;
        }
        if(cnt1*cnt2*cnt3==0) {cout<<0<<endl; continue;}
        for(long long int i=0;i<n;i++)
        {
            long long int tempans;
            if(a[i]=='1') tempans=max(mn2[i],mn3[i])+1-i;
            else if(a[i]=='2') tempans=max(mn1[i],mn3[i])+1-i;
            else tempans=max(mn1[i],mn2[i])+1-i;
            ans=min(ans,tempans);
        }
        cout<<ans<<endl;
    }
    return 0;
}