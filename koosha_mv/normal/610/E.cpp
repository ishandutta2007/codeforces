#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,K=10;

int n,m,k,a[N],lazy[4*N],seg[N*4][K][K];
string s;

void change(int L,int R,int val,int id, int l,int r);

void merge(int id,int u,int v){
	f(i,0,k){
		f(j,0,k){
			seg[id][i][j]=seg[u][i][j]+seg[v][i][j];
		}
	}
}
void build(int id,int l,int r){
	if(r-l<=1) return ;
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	merge(id,id*2+0,id*2+1);	
	seg[id][s[mid-1]-'a'][s[mid]-'a']++;
}
void shift(int id,int l,int r){
	if(lazy[id]==-1) return ;
	int mid=(l+r)/2;
	change(l,mid,lazy[id],id*2+0,l,mid);
	change(mid,r,lazy[id],id*2+1,mid,r);
   lazy[id]=-1;
}
void change(int L,int R,int val,int id=1, int l=0,int r=n){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]=val;
      f(i,0,k) f(j,0,k) seg[id][i][j]=0;
      seg[id][val][val]=r-l-1;
      return ;   
   }
   int u=-1,v=-1,mid=(l+r)>>1;
   shift(id,l,r);
   f(i,0,k){
   	f(j,0,k){
   		if(seg[id][i][j]!=seg[id*2+0][i][j]+seg[id*2+1][i][j]){
				u=i,v=j;
			}
		}
	}
	if(lazy[id]!=-1) u=lazy[id],v=lazy[id];
	if(u==-1 && v==-1){
		eror(id);
	}
	if(L<mid && mid<=R){
		u=val;
	}
	if(L<=mid && mid<R){
		v=val;
	}
   change(L,R,val,id*2+0,l,mid);
   change(L,R,val,id*2+1,mid,r);
   merge(id,id*2+0,id*2+1);
   seg[id][u][v]++;
}

int main(){
	fill(lazy,lazy+4*N,-1);
	cin>>n>>m>>k>>s;
	build(1,0,n);
	f(i,0,m){
		int type,l,r;
		cin>>type;
		if(type==1){
			char c;
			cin>>l>>r>>c;
			change(l-1,r,c-'a');
		}
		else{
			int ans=0;
			string s;
			cin>>s;
			f(i,0,s.size()){
				f(j,0,i+1){
					int u=s[i]-'a',v=s[j]-'a';
					ans+=seg[1][u][v];
				}
			}
			cout<<ans+1<<endl;
		}
	}
}