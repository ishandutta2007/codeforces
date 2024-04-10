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

struct SubMatrix{
   vector<vector<int>>p;
   SubMatrix(){}
   SubMatrix(vector<vector<int>>&v){
      int R=sz(v),C=sz(v[0]);
      p.assign(R+1, vector<int>(C+1));
      rep(r,R) rep(c,C) p[r+1][c+1]=v[r][c]+p[r][c+1]+p[r+1][c]-p[r][c];
   }
   int sum(int u,int l,int d,int r){
      return p[d][r]-p[d][l]-p[u][r]+p[u][l];
   }
};

const int MAXN=205;
const int inf=1e18;

pii dp[MAXN][MAXN];
vector<vector<int>>C;
SubMatrix S;
int n;



void pre(){
   rep(i,MAXN) dp[i][i]={0,i};
}

int get(int i, int j, int k){
   int res=0;
   res+= (k>i) ? dp[i][k-1].st : 0ll;
   res+= (k<j) ? dp[k+1][j].st : 0ll;
   debug(res);

   debug(i,j,k);

   int A=S.sum(0,i,i,k);
   int B=S.sum(k,i,n,k);
   int C=S.sum(0,k+1,k+1,j+1);
   int D=S.sum(j+1,k+1,n,j+1);

   debug(A,B,C,D);
   return res+A+B+C+D;
}

int res[MAXN];

void dfs(pii p, int a){
   auto [x,y]=p;
   if(x>y)return;

   int s=dp[x][y].nd;
   res[s]=a;

   dfs({x,s-1},s);
   dfs({s+1,y},s);
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   pre();

   cin>>n;
   C.assign(n,vector<int>(n));
   rep(i,n) rep(j,n) cin>>C[i][j];
   S=SubMatrix(C);

   for(int l=1;l<n;l++)for(int i=0;i+l<n;i++){
      int j=l+i;
      dp[i][j]={inf,-1};
      for(int k=i;k<=j;k++)
         dp[i][j]=min(dp[i][j],make_pair(get(i,j,k),k));
      debug(i,j,dp[i][j]);
   }

   dfs({0,n-1},-1);
   rep(i,n) cout<<res[i]+1<<" ";
   cout<<endl;

}

// [res]: 0, 
// [i,j,k]: 0, 1, 0, 
// [A,B,C,D]: 0, 0, 566, 269, 
// [res]: 0, 
// [i,j,k]: 0, 1, 1, 
// [A,B,C,D]: 0, 567, 0, 0, 
// [i,j,dp[i][j]]: 0, 1, (567, 1), 
// [res]: 0, 
// [i,j,k]: 1, 2, 1, 
// [A,B,C,D]: 0, 0, 240, 1, 
// [res]: 0, 
// [i,j,k]: 1, 2, 2, 
// [A,B,C,D]: 566, 269, 0, 0, 
// [i,j,dp[i][j]]: 1, 2, (241, 1), 
// [res]: 0, 
// [i,j,k]: 2, 3, 2, 
// [A,B,C,D]: 0, 0, 31, 0, 
// [res]: 0, 
// [i,j,k]: 2, 3, 3, 
// [A,B,C,D]: 240, 1, 0, 0, 
// [i,j,dp[i][j]]: 2, 3, (31, 2), 
// [res]: 0, 
// [i,j,k]: 0, 2, 0, 
// [A,B,C,D]: 0, 0, 567, 31, 
// [res]: 598, 
// [i,j,k]: 0, 2, 1, 
// [A,B,C,D]: 0, 567, 240, 1, 
// [res]: 567, 
// [i,j,k]: 0, 2, 2, 
// [A,B,C,D]: 0, 270, 0, 0, 
// [i,j,dp[i][j]]: 0, 2, (598, 0), 
// [res]: 0, 
// [i,j,k]: 1, 3, 1, 
// [A,B,C,D]: 0, 0, 270, 0, 
// [res]: 270, 
// [i,j,k]: 1, 3, 2, 
// [A,B,C,D]: 566, 269, 31, 0, 
// [res]: 241, 
// [i,j,k]: 1, 3, 3, 
// [A,B,C,D]: 567, 31, 0, 0, 
// [i,j,dp[i][j]]: 1, 3, (270, 1), 
// [res]: 0, 
// [i,j,k]: 0, 3, 0, 
// [A,B,C,D]: 0, 0, 567, 0, 
// [res]: 567, 
// [i,j,k]: 0, 3, 1, 
// [A,B,C,D]: 0, 567, 270, 0, 
// [res]: 837, 
// [i,j,k]: 0, 3, 2, 
// [A,B,C,D]: 0, 270, 31, 0, 
// [res]: 598, 
// [i,j,k]: 0, 3, 3, 
// [A,B,C,D]: 0, 31, 0, 0, 
// [i,j,dp[i][j]]: 0, 3, (567, 0),