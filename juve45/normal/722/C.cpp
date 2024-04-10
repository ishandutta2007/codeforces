#include <bits/stdc++.h>
#define DMAX 100009
using namespace std;
long long a[DMAX], b[DMAX], mask[DMAX];
map<pair<long long, long long>, long long> m;
long long ml[DMAX];
long long mr[DMAX], n;
long long ans;
vector <long long> sol;
int main()
{
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(long long i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    reverse(b+1, b+n+1);
    ans=0;

    for(long long i=1; i<=n; i++)
    {
        sol.push_back(ans);
        long long ok=0;
        long long del=b[i];
        long long right=ml[del+1];
        long long left=mr[del-1];

        mask[del]=1;
        if(mask[del-1]==1 && mask[del+1]==1)
        {
            ml[left]=right;
            long long sum=m[ {del+1, right}];
            m.erase({del+1, right});
            mr[right]=left;
            sum+=m[ {left, del-1}];
            m.erase({left, del-1});
            sum+=a[del];
            m[ {left, right}]=sum;
            if(sum>ans)
                ans=sum;
            continue;
        }
        if(mask[del+1]==1)
        {
            /// I go right
            ml[del]=right;
            mr[right]=del;
            long long sum=m[ {del+1, right}];
            m.erase({del+1, right});
            m[ {del, right}]=sum+a[del];

            if(ans<sum+a[del])
                ans=sum+a[del];
            ok=1;
        }
        if(mask[del-1]==1)
        {
            /// I go left
            mr[del]=left;
            ml[left]=del;
            long long sum=m[ {left, del-1}];
            m.erase({left, del-1});
            m[ {left, del}]=sum+a[del];
            if(ans<sum+a[del])
                ans=sum+a[del];
            ok=1;
        }
        if(ok==0)
        {
            ml[del]=del;
            mr[del]=del;
            m[ {del, del}]=a[del];
            ans=max(ans, a[del]);
        }
    }

    for(long long i=n-1; i>=0; i--)
        cout<<sol[i]<<'\n';

    return 0;
}