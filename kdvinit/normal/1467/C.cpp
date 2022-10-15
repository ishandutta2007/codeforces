/*
K.D. Vinit  |,,|
Hello
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int n=n1+n2+n3;

    int a[n1+1],b[n2+1],c[n3+1];
    int ans=0,sum1=0,sum2=0,sum3=0;

    for(int i=1;i<=n1;i++) { cin>>a[i]; ans+=a[i]; sum1+=a[i]; }
    for(int i=1;i<=n2;i++) { cin>>b[i]; ans+=b[i]; sum2+=b[i]; }
    for(int i=1;i<=n3;i++) { cin>>c[i]; ans+=c[i]; sum3+=c[i]; }

    sort(a+1,a+n1+1);
    sort(b+1,b+n2+1);
    sort(c+1,c+n3+1);

    int d[4];
    d[1]=a[1];
    d[2]=b[1];
    d[3]=c[1];
    sort(d+1,d+4);
    int val=d[1]+d[2];

    val=min(val,sum1);
    val=min(val,sum2);
    val=min(val,sum3);

    ans-=(2*val);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}