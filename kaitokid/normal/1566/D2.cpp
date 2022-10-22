#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],n,m,id[100009];
int bit[100009],fr[100009];
deque<int>pos[100009];

void add(int x)
{
    while(x<=n*m)
    {
        bit[x]++;
        x+=(x&(-x));

    }
}
ll cal(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));

    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int>hs;
        for(int i=1;i<=n*m;i++){cin>>a[i];hs.push_back(a[i]);pos[i].clear();fr[i]=0;}
        sort(hs.begin(),hs.end());
        vector<int>h;
        h.push_back(hs[0]);
        for(int i=1;i<hs.size();i++)
            if(hs[i]>hs[i-1])h.push_back(hs[i]);
        for(int i=1;i<=n*m;i++)
        {a[i]=lower_bound(h.begin(),h.end(),a[i])-h.begin();
        pos[a[i]].push_back(i);
        fr[a[i]]++;}
        ll ans=0;
        sort(a+1,a+n*m+1);
        for(int i=0;i<n;i++)
          {
              for(int j=1;j<=n*m;j++)bit[j]=0;
              for(int j=0;j<m;j++)
        {
            int u=a[i*m+j+1];
            if(fr[u]>=m-j)
                {

                    ans+=cal(pos[u].front()-1);
                    pos[u].pop_front();
                    fr[u]--;
                    continue;

                    }

            ans+=cal(pos[u].back());
            add(pos[u].back());
            pos[u].pop_back();
            fr[u]--;

        }
          }
         cout<<ans<<endl;

    }
    return 0;
}