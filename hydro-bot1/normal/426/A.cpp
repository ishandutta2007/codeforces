// Hydro submission #6253de03ca53060146718446@1649663491758
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,i,s,m=0;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        m+=a[i];
    }
    sort(a,a+n);
    m-=a[n-1];
    if(m>s) printf("NO\n");
    else printf("YES\n");
    return 0;
}