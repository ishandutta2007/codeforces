#include <bits/stdc++.h>

using namespace std;
double k,a[100000],ans1,ans2;int n,n1,n2;
int main()
{
    cin>>n>>n1>>n2;if(n1<n2)swap(n1,n2);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int i=0;
    for(i=n-1;i>=n-n2;i--)ans1+=a[i];ans1/=double(n2);
    for(int j=i;j>=n-n2-n1;j--)ans2+=a[j];ans2/=double(n1);
    cout<<setprecision(log10(ans1+ans2)+7)<<ans1+ans2;;

    return 0;
}