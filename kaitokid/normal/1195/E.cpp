    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    int n,m,a,b;
    ll x,y,z;
    int g[9004009];
    int le[3009][3009];
  deque<pair<ll,int> > ml;
    ll ans;
    int main()
    {
        //ios::sync_with_stdio(0);
        //cin.tie(0);
        scanf("%d%d%d%d",&n,&m,&a,&b);
        scanf("%d%I64d%I64d%I64d",&g[0],&x,&y,&z);
    for(int i=1;i<9004009;i++)g[i]=(x*g[i-1]+y)%z;
    for(int i=1;i<=n;i++)
    {
        ml.clear();
        for(int j=1;j<=b;j++)
         {
             while(!ml.empty()&&ml.back().first>=g[(i-1)*m+j-1])ml.pop_back();
            ml.push_back(make_pair(g[(i-1)*m+j-1],j));
         }
        le[i][b]=(*ml.begin()).first;
        for(int j=b+1;j<=m;j++){
       while(!ml.empty()&&ml.back().first>=g[(i-1)*m+j-1])ml.pop_back();
        while(!ml.empty()&&ml.front().second<=j-b)ml.pop_front();
        ll rtr=g[(i-1)*m+j-1];

        ml.push_back(make_pair(rtr,j));
        le[i][j]=(ml.front()).first;}

    }
    for(int j=b;j<=m;j++)
        {
            ml.clear();
            for(int i=1;i<=a;i++)
            {
             while(!ml.empty()&&ml.back().first>=le[i][j])ml.pop_back();

                ml.push_back(make_pair(le[i][j],i));
            }
            ans+=(ml.front()).first;

            for(int i=a+1;i<=n;i++){
     while(!ml.empty()&&ml.back().first>=le[i][j])ml.pop_back();
        while(!ml.empty()&&ml.front().second<=i-a)ml.pop_front();
        ll rtr=le[i][j];

        ml.push_back(make_pair(rtr,i));
        ans+=ml.front().first;
                    }

        }
        cout<<ans;

        return 0;
    }