// Hydro submission #629876311008115bd64c9093@1654158898085
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int f(int a)
{
    return a?a/abs(a):0;
}
int main()
{
    int t,n,x,y,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        if(n%2)
        {
            printf("NO\n");
            continue;
        }
        sort(a,a+n);
        for(i=1;i<n/2;i++)
        if(f(a[i]-a[i+n/2])*f(a[i]-a[i+n/2-1])<=0)
        {
            printf("NO\n");
            goto next;
        }
        for(i=n/2;i<n-1;i++)
        if(f(a[i]-a[i-n/2])*f(a[i]-a[i-n/2+1])<=0)
        {
            printf("NO\n");
            goto next;
        }
        printf("YES\n");
        for(i=0;i<n/2;i++)
        printf("%d %d ",a[i],a[n/2+i]);
        cout<<endl;next:;
    }
    return 0;
}