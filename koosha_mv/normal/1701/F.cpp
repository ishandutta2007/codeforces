#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99;

int n=2e5+10,q,d,a[N];
ll ans;

struct node{
	int sum=0,cnt=0,lz=0;
	node(int s=0,int c=0){
		sum=s,cnt=c,lz=0;
	}
	node friend operator + (node A,node B){
		A.sum+=B.sum;
		A.cnt+=B.cnt;
		A.lz=0;
		return A;
	}
	void add(int val){
		sum+=cnt*val;
		lz+=val;
	}
} seg[N<<2];

void shift(int ,int ,int );

node get(int L,int R,int id=1,int l=1,int r=n+1){
	if(R<=l || r<=L) return node();
	if(L<=l && r<=R){
		return seg[id];
	}
	int mid=(l+r)>>1;
	shift(id,l,r);
	node ans=get(L,R,id<<1,l,mid)+get(L,R,id<<1|1,mid,r);
	return ans;
}
void add(int L,int R,int val,int id=1,int l=1,int r=n+1){
	if(R<=l || r<=L) return ;
	if(L<=l && r<=R){
		seg[id].add(val);
		return ;
	}
	int mid=(l+r)>>1;
	shift(id,l,r);
	add(L,R,val,id<<1,l,mid);
	add(L,R,val,id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void tert(int x,int s,int c,int id=1,int l=1,int r=n+1){
	if(r<=x || x<l) return ;
	if(l+1==r){
		seg[id]=node(s,c);
		return ;
	}
	int mid=(l+r)>>1;
	shift(id,l,r);
	tert(x,s,c,id<<1,l,mid);
	tert(x,s,c,id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void shift(int id,int l,int r){
	int mid=(l+r)>>1;
	add(l,mid,seg[id].lz,id<<1,l,mid);
	add(mid,r,seg[id].lz,id<<1|1,mid,r);
	seg[id].lz=0;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>q>>d;
	//tert(1,0,1);
	//eror(get(1,2).cnt);
	//add(1,n,1);
	//eror(get(1,2).sum);
	while(q--){
		int x;
		cin>>x;
		if(a[x]==0){
			ans+=get(max(1ll,x-d),x).sum;
			add(max(1ll,x-d),x,+1);
			int res=get(x+1,x+d+1).cnt;
			tert(x,res,1);
			ans+=res*(res-1)/2;
		}
		else{
			add(max(1ll,x-d),x,-1);
			ans-=get(max(1ll,x-d),x).sum;
			int res=get(x+1,x+d+1).cnt;
			tert(x,0,0);
			ans-=res*(res-1)/2;
		}
		//f(i,1,6) cout<<get(i,i+1).cnt<<" "<<get(i,i+1).sum<<endl;
		//cout<<"ans : ";
		cout<<ans<<endl;
		a[x]^=1;
	}
}
/*
4 10
1
2
3
4

7 10
1
2
3
4
5
4 
3
*/