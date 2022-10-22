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

const int N=4e6+99;

struct node{
	int cnt0,cnt1,l0,l1;
};

int n,m,a[N],lazy[N];
node seg[N];

node merge(node a,node b){
	node ans;
	ans.cnt0=a.cnt0+b.cnt0;
	ans.cnt1=a.cnt1+b.cnt1;
	ans.l0=max(a.cnt0+b.l0,a.l0+b.cnt1);
	ans.l1=max(a.cnt1+b.l1,a.l1+b.cnt0);
	return ans;
}
void swp(int id){
	swap(seg[id].l0,seg[id].l1);
	swap(seg[id].cnt0,seg[id].cnt1);
}
void shift(int id){
	if(lazy[id]){
		swp(id*2+0);
		swp(id*2+1);
		lazy[id*2+0]^=1;
		lazy[id*2+1]^=1;
	}
   lazy[id]=0;
}
void build(int id,int l,int r){
	if(l+1==r){
		seg[id].l0=1;
		seg[id].l1=1;
		if(a[l]==0) seg[id].cnt0=1;
		else seg[id].cnt1=1;
		return ;
	}
	int mid=(l+r)>>1;
   build(id*2+0,l,mid);
   build(id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
void change(int id,int L,int R,int l,int r){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]^=1;
      swp(id);
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   change(id*2+0,L,R,l,mid);
   change(id*2+1,L,R,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1){
		char c;
		cin>>c;
		a[i]=(c=='7');
	}
	build(1,1,n+1);
	f(i,0,m){
		string s;
		cin>>s;
		if(s[0]=='s'){
			int l,r;
			cin>>l>>r;
			change(1,l,r+1,1,n+1);
		}
		else{
			cout<<seg[1].l0<<endl;
		}
	}
}
/*
3 2
747
switch 1 1
count
switch 1 3
count
*/