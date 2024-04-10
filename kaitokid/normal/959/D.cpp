    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    ll n,x,wh=0;
    int pr[10000010];
    bool vis[10000010];
    bool ch(ll x)
    {

       while(x>1)
    {
        if(pr[x]==0)pr[x]=x;
        int d=pr[x];
        if(vis[d]==true) return false;
        while(x%d==0)x/=d;

    }


    return true;
    }
    int main()
    {
        ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<4000;i++)
    {
        if(pr[i]>0)continue;
        pr[i]=i;
        for(int j=i*i;j<10000008;j+=i)pr[j]=i;
    }
        cin>>n;


        for(int i=0;i<n;i++)
        {
    wh=i+1;
            cin>>x;
            if(ch(x)){cout<<x<<" ";
            while(x>1)
    {
        if(pr[x]==0)pr[x]=x;
        int d=pr[x];
        vis[d]=true;
        while(x%d==0)x/=d;
    }

            continue;}
            x++;
            while(!ch(x))x++;
           cout<<x<<" ";

    while(x>1)
    {
        if(pr[x]==0)pr[x]=x;
        int d=pr[x];
        vis[d]=true;
        while(x%d==0)x/=d;
    }
           break;

        }
        ll u=2;
        for(int i=wh;i<n;i++)
        {
            if(pr[u]==0)pr[u]=u;
            while(((pr[u]!=u&&pr[u]!=0)||(vis[u]==true)))u++;

            cout<<u<<" ";
            u++;
        }
        return 0;
    }