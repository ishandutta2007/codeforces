#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>,null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
map<int,int>mp;
ordered_set st;
int u=0;
int ch(int x)
{
    int ans=u+x;

    ans-=st.order_of_key({x+1,-1});
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int lst=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        int l=0,r=1100000000;
        if(ch(0)<x)
        {
        while(l<r)
        {
            int mid=(l+r+1)/2;

            if(ch(mid)<x)l=mid;
            else r=mid-1;
        }
        //cout<<1<<" "<<l<<endl;
        u++;
        st.insert({l+1,mp[l+1]++});
        }
        l=0,r=1100000000;
        while(l<r)
        {
           int mid=(l+r)/2;
            if(ch(mid)>x)r=mid;
            else l=mid+1;
        }
        st.insert({l,mp[l]++});
        //cout<<2<<" "<<l<<endl;
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int x;

        scanf("%d",&x);
            x=(x+lst)%1000000001;
            lst=ch(x);
            printf("%d\n",lst);
        }
    }
    return 0;
}