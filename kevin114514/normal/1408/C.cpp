#include<bits/stdc++.h>
using namespace std;
int n,l;
int f[100100];
double ta[100100],tb[100100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>l;
        for(int i=1;i<=n;i++)
            cin>>f[i];
        for(int i=0;i<=n+1;i++)
        	ta[i]=tb[i]=0;
        f[n+1]=l;
        for(int i=1;i<=n+1;i++)
            ta[i]=ta[i-1]+1.0*(f[i]-f[i-1])/i;
        for(int i=n;i>=0;i--)
            tb[i]=tb[i+1]+1.0*(f[i+1]-f[i])/(n-i+1);
        int now=0;
        while(ta[now]<=tb[now])
            now++;
//        cout<<now<<endl;
        double timea=ta[now-1],timeb=tb[now];
//        cout<<timea<<" "<<timeb<<endl;
        double dist=f[now]-f[now-1];
        dist+=(timeb-timea)*(n-now+2);
        printf("%.8lf\n",timea+dist/(n+2));
    }
    return 0;
}