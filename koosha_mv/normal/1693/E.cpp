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

const int N=2e5+99;

struct node{
	pair<int,int> res[3];
	node(int x=0,int y=0){
		if(!x && !y){
			f(i,0,3) res[i]={0,i};
		}
		if(x && !y){
			res[0]={0,1};
			res[1]={0,1};
			res[2]={1,0};
		}
		if(!x && y){
			res[0]={0,2};
			res[1]={1,0};
			res[2]={0,2};
		}
		if(x && y){
			res[0]=res[1]=res[2]={1,0};
		}
	}
	node friend operator + (node A,node B){
		node ans;
		swap(A,B);
		f(i,0,3){
			ans.res[i]={A.res[i].F+B.res[A.res[i].S].F,B.res[A.res[i].S].S};
		}
		//f(i,0,3) erorp(ans.res[i]);
		return ans;
	}
} seg[N<<2];

int n,t,a[N],cnt0[N],cnt1[N];
ll sum;

void build(int id=1,int l=0,int r=n+1){
	if(l+1==r){
		seg[id]=node(cnt0[l],cnt1[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void update(int x,int id=1,int l=0,int r=n+1){
	if(r<=x || x<l) return ;
	if(l+1==r){
		seg[id]=node(cnt0[l],cnt1[l]);
		return ;
	}
	int mid=(l+r)>>1;
	update(x,id<<1,l,mid);
	update(x,id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
node get(int L,int R,int id=1,int l=0,int r=n+1){
	if(r<=L || R<=l) return node();
	if(L<=l && r<=R){
		return seg[id];
	}
	int mid=(l+r)>>1;
	return get(L,R,id<<1,l,mid)+get(L,R,id<<1|1,mid,r);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cnt0[0]=1,cnt1[0]=1;
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) cnt1[a[i]]++;
	build();
	f(i,1,n+1){
		node ans=get(0,a[i]);
		sum+=ans.res[0].F;
		cnt0[a[i]]++;
		cnt1[a[i]]--;
		update(a[i]);
	}
	cout<<sum;
}