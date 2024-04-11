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

const int N=(1<<21),lg=19,k=(1<<lg);

struct node{
	int ans,F,S,sz;
};

int n,t,e,u,a[N],l[N],r[N],h[N],d[N],ans[N];
node seg[N];

node merge(node a,node b){
	node ans;
	ans.ans=min(a.ans,b.ans);
	ans.F=a.F;
	ans.S=b.S+b.sz;
	if(a.F!=0 && b.F!=0) minm(ans.ans,b.F+b.sz-a.S);
	if(a.F==0){
		if(b.F==0) ans.F=0;
		else ans.F=b.F+b.sz;
	}
	if(b.S==0) ans.S=a.S;
	ans.sz=a.sz+b.sz;
	return ans;
}
void build(){
	d[0]=1;
	f(i,k,2*k)
		seg[i].sz=1,seg[i].ans=k;
	f(i,2,2*k){
		h[i]=h[i/2]+1;
		d[h[i]]=i;
	}
	f_(i,k-1,1){
		l[i]=i*2+0,r[i]=i*2+1;
		seg[i]=merge(seg[i*2+0],seg[i*2+1]);
		//cout<<i<<" : "<<seg[i].ans<<" "<<seg[i].F<<" "<<seg[i].S<<" "<<seg[i].sz<<endl;
	}
}
void change(int x){
	f(i,d[x]/2+1,d[x]+1)
		swap(l[i],r[i]);
	f_(i,d[x],1)
		seg[i]=merge(seg[l[i]],seg[r[i]]);
}
void Add(int x){
	if(u&(1<<x)) Add(x-1);
	u^=(1<<x);
	change(lg-x-1);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>e;
	f(i,0,n){
		int x;
		cin>>x;
		seg[k+x].F=1;
		seg[k+x].S=1;
		seg[k+x].ans=1;
	}
	build();
	for(;;Add(lg-1)){
		ans[u]=seg[1].ans;
		if(u==k-1) break;
	}
	f(i,0,(1<<e))
		cout<<ans[i]<<" ";
}