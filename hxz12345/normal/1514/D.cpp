#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 10 ;
int sum,lft,rit,n , m , a[N] , b[N] , bl[N] , unt = 0 , L[710] , R[710] , mx[710][710] , tot[N] , pos[N] ;
vector < int > v[N] ;
inline int query(int l , int r) { int ans = 0 ;
  if(bl[l] == bl[r]) {
    for(register int i = l ; i <= r ; i ++) tot[a[i]] = 0 ;
    for(register int i = l ; i <= r ; i ++) ans = max(ans , ++ tot[a[i]]) ;
    return ans ;
  } ans = mx[bl[l] + 1][bl[r] - 1] ;
  for(register int i = l ; i <= R[bl[l]] ; i ++) {
    int it = pos[i] ; while(it + ans < v[a[i]].size() && v[a[i]][it + ans] <= r) ++ ans ;
  }
  for(register int i = L[bl[r]] ; i <= r ; i ++) {
    int it = pos[i] ; while(it - ans >= 0 && v[a[i]][it - ans] >= l) ++ ans ;
  } return ans ;
}
int make(int x)
{
	int ans=0;
	if (x % 2==0) ans=x/2;
	else ans=x/2+1;
	return ans;
}
signed main() {
  ios :: sync_with_stdio(false) ;
  cin.tie(0) ;cout.tie(0) ;
  cin >> n >> m ;
  for(register int i = 1 ; i <= n ; i ++) { cin >> a[i] ; b[i] = a[i] ; }
  sort(b + 1 , b + n + 1) ;
  int len = unique(b + 1 , b + n + 1) - b - 1 ;
  for(register int i = 1 ; i <= n ; i ++) { a[i] = lower_bound(b + 1 , b + len + 1 , a[i]) - b ; }
  for(register int i = 1 ; i <= n ; i ++) { v[a[i]].push_back(i) ; pos[i] = v[a[i]].size() ; pos[i] -- ; }
  int unt = sqrt(n) ;
  for(register int i = 1 ; i <= n ; i ++) bl[i] = (i - 1) / unt + 1 ;
  for(register int i = 1 ; i <= bl[n] ; i ++) { L[i] = (i - 1) * unt + 1 ; R[i] = i * unt ; }
  R[bl[n]] = n ;
  for(register int i = 1 ; i <= bl[n] ; i ++) {
    memset(tot , 0 , sizeof(tot)) ;
    for(register int j = i ; j <= bl[n] ; j ++){
      mx[i][j] = mx[i][j - 1] ;
      for(register int k = L[j] ; k <= R[j] ; k ++) mx[i][j] = max(mx[i][j] , ++ tot[a[k]]) ;
    }
  }
  int lastans = 0 ;
  for(register int i = 1 ; i <= m ; i ++) {
    int l , r ; cin >> l >> r ;
    if(l > r) swap(l , r) ;
    sum=query(l,r);
    if (sum<=make(r-l+1)) cout<<1<<endl;
    else cout<<2*sum-(r-l+1)<<endl;
  }
  return 0 ;
}