#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)

typedef long long ll;
const int maxn=1e5+10;
int n,q,F[maxn],deg[maxn];ll A[maxn],tmp[maxn];

ll tag[maxn];multiset<ll>allmin,allmax,S[maxn];
void ins(int id){if(!S[id].empty())allmin.insert(*S[id].begin()+tag[id]),allmax.insert(*S[id].rbegin()+tag[id]);}
void era(int id){if(!S[id].empty())allmin.erase(allmin.find(*S[id].begin()+tag[id])),allmax.erase(allmax.find(*S[id].rbegin()+tag[id]));}

signed main(){
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>q;
  rep(i,1,n)cin>>A[i],deg[i]=2;
  rep(i,1,n)cin>>F[i],deg[F[i]]++;
  rep(i,1,n)tmp[F[i]]+=A[i]/deg[i],tmp[i]+=A[F[i]]/deg[F[i]]+A[i]-A[i]/deg[i]*(deg[i]-1);
  rep(i,1,n)S[F[i]].insert(tmp[i]);rep(i,1,n)ins(i);
  while(q--){
    int op,id;cin>>op;
    if(op==3){
      cout<<*allmin.begin()<<' '<<*allmax.rbegin()<<endl;continue;
    }
    cin>>id;
    if(op==1){
      int f=F[id];
      era(f),era(F[f]),era(F[F[f]]);
      S[f].erase(S[f].find(tmp[id]));
      S[F[f]].erase(S[F[f]].find(tmp[f]));
      S[F[F[f]]].erase(S[F[F[f]]].find(tmp[F[f]]));
      tmp[id]+=tag[f];
      tmp[f]-=A[id]/deg[id];
      tmp[id]-=A[f]/deg[f];
      ll de=A[f]/(deg[f]-1)-A[f]/deg[f];
      tag[f]+=de,tmp[F[f]]+=de,tmp[f]+=A[f]/deg[f]*(deg[f]-1)-A[f]/(deg[f]-1)*(deg[f]-2);
      S[F[f]].insert(tmp[f]);
      S[F[F[f]]].insert(tmp[F[f]]);
      ins(f),ins(F[f]),ins(F[F[f]]);
      deg[f]--;
      cin>>F[id];f=F[id];
      era(f),era(F[f]),era(F[F[f]]);
      S[F[f]].erase(S[F[f]].find(tmp[f]));
      S[F[F[f]]].erase(S[F[F[f]]].find(tmp[F[f]]));
      tmp[f]+=A[id]/deg[id];
      de=A[f]/(deg[f]+1)-A[f]/deg[f];
      tag[f]+=de,tmp[F[f]]+=de,tmp[f]+=A[f]/deg[f]*(deg[f]-1)-A[f]/(deg[f]+1)*deg[f];
      tmp[id]+=A[f]/(deg[f]+1);
      S[f].insert(tmp[id]-=tag[f]);
      S[F[f]].insert(tmp[f]);
      S[F[F[f]]].insert(tmp[F[f]]);
      ins(f),ins(F[f]),ins(F[F[f]]);
      deg[f]++;
    }else cout<<tmp[id]+tag[F[id]]<<endl;
  }
  return 0;
}