#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009];
int mn[100009];
int pr[100009],p[100009];
int n,q;
int sp[100009][30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<500;i++)
    {
        if(pr[i]!=0)continue;
        for(int j=i*i;j<=100000;j+=i)pr[j]=i;
    }

    for(int i=0;i<=100000;i++)
        {mn[i]=n+1;
    if(pr[i]==0)pr[i]=i;}
    p[n+1]=n+1;
    for(int i=n;i>0;i--)
    {
        vector<int>d;
        while(a[i]>1)
        {
            int g=pr[a[i]];
            d.push_back(g);
            while((a[i]%g)==0)a[i]/=g;
        }
        int w=p[i+1];
        for(int j=0;j<d.size();j++){w=min(w,mn[d[j]]);mn[d[j]]=i;}
        p[i]=w;
        sp[i][0]=w;
    }
    for(int j=1;j<=23;j++)
        for(int i=1;i<=n;i++)
        sp[i][j]=sp[sp[i][j-1]][j-1];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=23;i>=0;i--)
        if((sp[l][i]!=0)&&(sp[l][i]<=r)){l=sp[l][i];ans+=(1<<i);}
        ans++;
        cout<<ans<<endl;
    }

        return 0;
}