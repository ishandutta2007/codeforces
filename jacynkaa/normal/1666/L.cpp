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

const int MAXN=1e6;

vector<int>G[MAXN];
int pre[MAXN];
int color[MAXN];
   int n,m,s;


void pr(vector<int>A){
   cout <<sz(A)<<endl;
   for(int a:A) cout<<a+1<<" ";
   cout<<endl;
}

void pr(int a, int b){
   vector<int>A,B={a};
   while(b!=-1) {B.push_back(b); b=pre[b];}
   while(a!=-1) {A.push_back(a); a=pre[a];}
   reverse(all(A));
   reverse(all(B));

   cout<<"Possible\n";
   pr(A);
   pr(B);
   exit(0);
}

void dfs(int x, int c, int p){
   if(color[x]==c) return;
   if(color[x]!=-1) pr(x,p);

   color[x]=c;
   pre[x]=p;

   for(int y:G[x]) if(y!=s) dfs(y,c,x);

}


int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   rep(i,MAXN) color[i]=-1;

   cin>>n>>m>>s;
   --s;

   pre[s]=-1;

   rep(i,m){
      int a,b;
      cin>>a>>b;
      G[--a].push_back(--b);
   }

   int c=1;
   for(int x:G[s]) dfs(x,c++,s);

   cout<<"Impossible\n";
}