


#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds ; 

int ti = 0 ; 
template <class _T>
using ordered_set = tree<_T, null_type, std::less<_T>, rb_tree_tag, tree_order_statistics_node_update>;

void insert(ordered_set<pair<long long,int> > &src, pair<long long,int> it){
    src.insert(it) ; 
}

int query(ordered_set<pair<long long,int> > &src, long long l, long long r){
       pair<long long,int> lhs = {l, -1} ; 
       pair<long long,int > rhs = {r, 100000000} ; 
       return src.order_of_key(rhs) - src.order_of_key(lhs) ; 

}

const int N = 1e5 + 7;

int n; 

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
#ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
#endif

       cin >> n ; 
       vector< long long  > a(n), b; 
       for(auto &u : a)cin >> u; 

       if(n < 3){
              cout<<  ((*min_element(a.begin(),a.end())) >= 0 ? 0 : -1) ;
              return 0; 
       }

       for(int i = 1 ;i < n; ++ i){
              a[i] += a[i-1] ;
       }

       b = a ;
       sort(a.begin(), a.end()) ; 
       if(a[0] < 0 || a.back() != b.back())cout << -1 ; 
       else {
              ordered_set<pair<long long,int> > ol ;
              long long ans = 0 ;  
              for(int i = 0 ;i < n;++ i){
                     ans += query(ol, b[i] + 1, (long long) 1e18 ) ;
                     insert(ol, {b[i], ti++ }) ; 
              }
              cout << ans ; 
       }
       return 0;
}