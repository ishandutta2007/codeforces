#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99;

int n,m,res,L[N],R[N],ans[N];
set<pair<int,int> >::iterator it;
set<pair<int,int> > s[N*2];
vector<int> v[N];

int find(int l,int r){
   int R=r,res=N;
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1){
		   if(s[l].size() && (*s[l].begin()).F<R){
		      pair<int,int> p=mp(R,-1);
		      s[l].insert(p);
		      it=s[l].lower_bound(p),it--;
		      minm(res,(*it).S);
		      s[l].erase(p);
		   }
		   l++;
		}
		if (r&1){
		   r--;
		   if(s[r].size() && (*s[r].begin()).F<R){
		      pair<int,int> p=mp(R,0);
		      s[r].insert(p);
		      it=s[r].lower_bound(p),it--;
		      minm(res,(*it).S);
		      s[r].erase(p);
		   }
		}
	}
	return res;
}
void Add(int l,int r,int t){
   l+=n;
   while(l){
      pair<int,int> p=mp(r,t);
      s[l].insert(p);
      while(p!=*(s[l].rbegin()) && p.S<=(*s[l].upper_bound(p)).S)
         s[l].erase(*s[l].upper_bound(p));
      it=s[l].lower_bound(p);
      if(it!=s[l].begin() && (*(--it)).S<=p.S)
         s[l].erase(p);
      l/=2;
   }
}
void solve(int l,int r){
   if(r<=l) return ;
   int u=find(l,r);
   if(u==N) return ;
   res+=R[u]-L[u]+1;
   solve(l,L[u]);
   solve(R[u]+1,r);
}

int main(){
   cin>>n>>m;
   f(i,0,m){
      int l,r;
      Gett(L[i],R[i]);
      L[i]--,R[i]--;
      v[R[i]-L[i]].pb(i);
   }
   f_(i,n-1,0){
      res=0;
      f(j,0,v[i].size())
         Add(L[v[i][j]],R[v[i][j]],v[i][j]);
      solve(0,n);
      ans[i]=res;
   }
   f(i,0,n) cout<<ans[i]<<" ";
}