#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 5e5+7;
const int INF = 1e9+7;
int A[N],S[N],dp[N*2];
vector<int> V[N*2];
int pref[N*2];

int renum[N*2],rptr = 0,T[N*2];
void add(int pos,int delta){
    for(int i = pos;i<N*2;i+=i&-i)
        T[i]+=delta;
}
int get(int pos){
    int ret = 0;
    for(int i = pos;i>0;i-=i&-i)
        ret+=T[i];
    return ret;
}
void solve(){
   int n,d;
   cin>>n>>d;
   renum[++rptr] = d;

   for(int i = 1;i<=n;++i){
       cin>>S[i]>>A[i];
       renum[++rptr] = S[i];
       renum[++rptr] = A[i];
   }
   sort(renum+1,renum+1+rptr);
   map<int,int> M;
   int ptr = 0;
   renum[0] = -INF;
   for(int i = 1;i<=rptr;++i){
       if (renum[i]==renum[i-1])
           continue;
       M[renum[i]] = ++ptr;
   }
    d = M[d];
    vector<pair<int,int> > del;
   for(int i = 1;i<=n;++i){
       S[i] = M[S[i]];
       A[i] = M[A[i]];
       A[i] = max(A[i],d);
       if (S[i]>=A[i]){
           add(S[i],1);
           del.push_back({A[i],i});
       }
       else {
           V[S[i]].push_back(A[i]);
           ++pref[S[i]];
       }

   }
    sort(del.begin(),del.end());

   for(int i = 1;i<=ptr+1;++i){
        pref[i] += pref[i-1];
        dp[i] = INF;
   }
   dp[d] = pref[d-1];
    int cd = 0;
   for(int i = d;i<=ptr;++i){
       while(cd<del.size() && del[cd].first<=i){
           add(S[del[cd].second],-1);
           ++cd;
       }
       for(int to:V[i]){
           if (to<=i)
               continue;
           dp[to] = min(dp[to],dp[i]+pref[to-1]-pref[i-1]-1+get(to-1));
       }
       dp[i+1] = min(dp[i+1],dp[i]+pref[i]-pref[i-1]);
   }
  cout<<n-dp[ptr+1]<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}