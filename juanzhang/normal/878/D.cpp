#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=1e5+10;
int n,k,q,gkm,A[12][maxn],ans[maxn];
int chk[maxn],ls[maxn],rs[maxn],Qx[maxn],Qy[maxn];

vector<pii>qid[1<<12];

int main(){
  int tpq;cin>>n>>k>>tpq;gkm=k;
  rep(i,0,k-1)rep(j,1,n)scanf("%d",&A[i][j]);
  rep(_,1,tpq){
    int op;scanf("%d",&op);
    if(op==3){
      int&y=Qy[++q];scanf("%d%d",&Qx[q],&y);
      rep(i,0,k-1){
        int S=0;
        rep(j,0,k-1)if(A[i][y]<=A[j][y])S|=1<<j;
        qid[S].emplace_back(q,A[i][y]);
      }
    }else{
      chk[++gkm]=op,scanf("%d%d",ls+gkm,rs+gkm);
    }
  }
  rep(S,0,(1<<k)-1){
    static int val[maxn];
    rep(i,1,k)val[i]=S>>(i-1)&1;
    rep(i,k+1,gkm)val[i]=chk[i]==1?val[ls[i]]||val[rs[i]]:val[ls[i]]&&val[rs[i]];
    for(pii p:qid[S])if(!ans[p.first]&&val[Qx[p.first]])ans[p.first]=p.second;
  }
  rep(i,1,q)printf("%d\n",ans[i]);
  return 0;
}