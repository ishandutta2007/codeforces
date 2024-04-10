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

#define int long long

typedef pair<pii,pii> ppi;
typedef map<int,vector<ppi>> mpi;

 ppi secret={{11,11},{12,10}};

int dist(pii a, pii b){
   auto [x,y]=a;
   auto [q,w]=b;
   return abs(x-q)+abs(w-y);
}

int dist(pii a, pii b, pii c){
   return dist(a,b)+dist(a,c);
}

vector<int> get(mpi &a){
   vector<int>X;
   
   for(auto &[_,v]:a)X.push_back(sz(v));
   sort(all(X),greater<int>());
   return X;
}

void best(mpi &a, mpi b){
      if(get(a)>get(b)) swap(a,b);
}

int ask(int i, int j) {
    cout<<"SCAN "<<i+1<<" "<<j+1<<endl;

    //return dist({i,j},secret.st,secret.nd);
    int x;
    cin >> x;
    return x;
}

int dig(int i, int j){
   cout<<"DIG "<< i+1<<" "<<j+1<<endl;
   //return make_pair(i,j)==secret.st || make_pair(i,j)==secret.nd;
   int x;
   cin >> x;
   return x;
}

void solve(vector<ppi>V){
   for(auto [a,b]:V) if(dig(a.st,a.nd) && dig(b.st,b.nd)) return;
   assert(false);
}



void get(int n,int m,vector<ppi>V){
  // debug(V);
   //debug(sz(V));
   if(sz(V)==0) return ;
   if(sz(V)==1) {solve(V); return;}
   if(sz(V)==2) {solve(V); return;}

   pii q;
   mpi T={{0,V}};
   rep(i,n) rep(j,m){
      mpi X;
      for(auto [a,b]:V) X[dist({i,j},a,b)].push_back({a,b});
      best(T,X);
      if(X==T) q={i,j};
   }

   debug(q,V);

   int w=ask(q.st,q.nd);
   get(n,m,T[w]);

   // int res=0;
   // for(auto [_,v]:T) res=max(res,get(n,m,v));
   // return res+1;
}

void test(int n,int m){
   vector<ppi>V;
   rep(i,n) rep(j,m) rep(k,n) rep(l,m) if(make_pair(i,j)<make_pair(k,l))  V.push_back({{i,j},{k,l}});

   map<vector<int>,vector<ppi>> M;
   vector<pii>X={{0,0},{0,m-1}};

   vector<int> D={ask(0,0),ask(0,m-1)};

   vector<ppi>Vp;
   for(auto [a,b]:V){
      vector<int>S;
      for(auto x:X) S.push_back(dist(x,a,b));
      if(S==D)
         Vp.push_back({a,b});
   }
   get(n,m,Vp);

   // for(auto [_,V]:M){
   //  //  debug(sz(V));
   //    int res=get(n,m,V);
   //    R=max(res,R);
   //    // debug(n,m,res);
   // }
   // debug(R);   

   // map<vector<int>,int> M;
   // vector<pii>X={{0,0},{0,m-1},{n-1,0},{n-1,m-1}};

   // for(auto [a,b]:V){
   //    vector<int>S;
   //    for(auto x:X) S.push_back(dist(x,a,b));
   //    M[S]++;
   // }
   // debug(M);
 
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   // test(16,16);
   // for(int i=2;i<=16;i++)
   //    for(int j=i;j<=16;j++) test(i,j);
   int Z;
   cin>>Z;
   while(Z--){
      int n,m;
      cin>>n>>m;
      test(n,m);
   }

}