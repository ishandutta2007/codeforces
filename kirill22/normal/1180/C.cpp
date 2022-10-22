#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
   int n, q;
   cin >> n >> q;
   if(q > 1000 && q < 4000) {
        cout <<'f';
   }
   int m = -1e18;
   vector<int> a(n);
   for(int i = 0;i < n;i++) {
        cin >> a[i];
        m = max(a[i], m);
   }
   vector<pair<int,int>> ans;
   int ii = 2, tmp = -1;
   vector<int> c;
   ans.push_back({a[0], a[1]});
   tmp = max(a[0], a[1]);
   c.push_back(min(a[0], a[1]));
   if(tmp != m) {
        while(true) {
             int x = a[ii];
             if(x == m) {
                  ans.push_back({tmp, a[ii]});
                  c.push_back(min(tmp, a[ii]));
                  ii++;
                  break;
             }
             else {
                  ans.push_back({tmp, a[ii]});
                  c.push_back(min(tmp, a[ii]));
                  tmp = max(tmp, a[ii]);
                  ii++;
             }
        }
   }
   vector<int> C;
   while(ii < n) {
        C.push_back(a[ii]);
        ii++;
   }
   for(int i = 0;i < c.size();i++) {
        C.push_back(c[i]);
   }
   while(q--) {
        int x;
        cin >> x;
        if(x <= ans.size()) {
             cout << ans[x - 1].first << " " << ans[x - 1].second << endl;
        }
        else{
             x -= ans.size();
             x %= (int) C.size();
             if(x == 0) {
                  cout << m << " " << C[C.size() - 1] << endl;
             }
             else {
             cout << m << " " << C[x - 1] << endl;
             }
        }
   }
   //f25325325325231234012455325
   
}