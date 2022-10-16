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


int get(pii a, pii  b){
   auto [x1,y1]=a;
   auto [x2,y2]=b;
   return abs(x1-x2)+abs(y1-y2);
}

vector<pair<pii,pii>>res;

void add(pii a, pii b){
   res.push_back({a,b});
}

void pr(pii a, pii b){
   auto [x1,y1]=a;
   auto [x2,y2]=b;
   cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   vector<pii>X(3);
   rep(i,3) cin>>X[i].st>>X[i].nd;
   sort(all(X));

   debug(X);

   // int res=get(X[0],X[1])+get(X[1],X[2])+get(X[2],X[0]);
   // cout<<res/2<endl;

   int av_x=X[1].st;
   int min_y=min({X[0].nd,X[1].nd,X[2].nd});
   int max_y=max({X[0].nd,X[1].nd,X[2].nd});
   
   if(min_y!=max_y)
      add({av_x,min_y},{av_x,max_y});
   for(auto [x,y]:X) if(x!=av_x) add({x,y},{av_x,y});

   cout<<sz(res)<<endl;
   for(auto [a,b]:res)pr(a,b);
}