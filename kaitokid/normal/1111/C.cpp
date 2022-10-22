    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    #define ordered_set tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update>
    map<int,int> mp;
   ordered_set ors;
   int n,k,a,b,x;
   ll go(int fr,int en)
   {
       ll num =ors.order_of_key(en+1)-ors.order_of_key(fr);
       if(num==0)return a;
       if(fr==en)return num*b;
       int mid=(fr+en)/2;
       return min((en-fr+1)*num*b,go(fr,mid)+go(mid+1,en));
   }
   int main()
    {
        ios::sync_with_stdio(0);
 cin>>n>>k>>a>>b;
 for(int i=0;i<k;i++){cin>>x;ors.insert(x+(0.0000001)*mp[x]);mp[x]++;}
 int rr=1;
 for(int i=0;i<n;i++)rr*=2;
 cout<<go(1,rr);
        return 0;
    }