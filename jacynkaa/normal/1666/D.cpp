#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(X) (int)((X).size())
#define st first
#define nd second
#define pii pair<int,int>
#define all(X) (X).begin(), (X).end()

#ifdef LOC
auto& operator<<(auto& out, pair<auto,auto> a) {return out<<"("<<a.st<<", "<<a.nd<<")";}
auto& operator<<(auto& out, auto a) {
   out << "{";
   for(auto b:a) out<<b<<", ";
   return out<<"}";
}

void dump(auto... x) {((cerr<<x<<", "),...) <<"\n";}
#define debug(...) cerr<< "[" #__VA_ARGS__ "]: ",dump(__VA_ARGS__)
#else
#define debug(...) 0
#endif


int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin >> T;
   while(T--) {
       string a,b;
       cin >> a >> b;
       vector<int> used(256);
       int pos = 0;
       int bd=0;

       reverse(all(a));
       reverse(all(b));
        vector<int> nxt(a.size());
        int i=a.size()-1;
       for(auto x:a) {
            if(pos < b.size() && x == b[pos]) {
                nxt[i] = 1;
                pos++;
            }
           i--;
       }

       reverse(all(a));
       reverse(all(b));

        pos = 0;
        i=0;
       for(auto x:a) {
            if(nxt[i]) {
                used[x] = 1;
                pos++;
            }
            else if(used[x])
                bd = 1;
            i++;
       }

       if(bd || pos < b.size())
        cout<<"NO\n";
       else
        cout<<"YES\n";
   }
}