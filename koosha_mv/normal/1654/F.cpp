#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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

const int N=(1<<20),S=1,base=37,mod[S]={998344353};

int n,cnt=1,pl[N],pr[N],ps[N][S],pseg[N],L[N],R[N],seg[N][S],Pow[S][N],mark[N];
vector<int> vec;
string t;

void upd1(int id,int l,int r){
	f(s,0,S) seg[id][s]=(seg[L[id]][s]+1ll*seg[R[id]][s]*Pow[s][(r-l)>>1]%mod[s])%mod[s];
}
void build(int id=1,int l=0,int r=(1<<n)){
	if(l+1==r){
		f(s,0,S) seg[id][s]=t[l]-'a'+1;
		return ;
	}
	L[id]=id*2;
	R[id]=id*2+1;
	int mid=(l+r)>>1;	
	build(L[id],l,mid);
	build(R[id],mid,r);
	upd1(id,l,r);
}
void change(int id,int l,int r,int h){
	if(h==0){
		if(mark[id]==0){
			vec.pb(id);
			mark[id]=1;
			pl[id]=L[id];
			pr[id]=R[id];
			f(s,0,S) ps[id][s]=seg[id][s];
		}
		swap(L[id],R[id]);
		upd1(id,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	change(L[id],l,mid,h-1);
	change(R[id],mid,r,h-1);
	if(mark[id]==0){
		vec.pb(id);
		mark[id]=1;
		pl[id]=L[id];
		pr[id]=R[id];
		f(s,0,S) ps[id][s]=seg[id][s];
	}
	upd1(id,l,r);
}
int getl(int id){
	if(pl[id]==-1) return L[id];
	return pl[id];
}
int getr(int id){
	if(pr[id]==-1) return R[id];
	return pr[id];
}
int gets(int id,int s){
	if(ps[id][s]==-1) return seg[id][s];
	return ps[id][s];
}
void do_it(int now){
	int b=0;
	f(s,0,S) if(seg[1][s]!=gets(1,s)) b=1;
	if(b==0) return ;
	int id1=1,id2=1;
	f(i,0,n){
		int b=0;
		f(s,0,S) if(seg[L[id1]][s]!=gets(getl(id2),s)) b=1;
		if(b==1){
			id1=L[id1];
			id2=getl(id2);
		}
		else{
			id1=R[id1];
			id2=getr(id2);
		}
	}
	if(seg[id1][0]<gets(id2,0)){
		for(auto x : vec){
			mark[x]=0;
			pl[x]=-1;
			pr[x]=-1;
			f(s,0,S) ps[x][s]=-1;
		}
		vec.clear();
	}
}
void pert(int id,int h){
	if(h==0){
		cout<<char('a'-1+gets(id,0));
		return ;
	}
	pert(getl(id),h-1);
	pert(getr(id),h-1);
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fill(pl,pl+N,-1);
	fill(pr,pr+N,-1);
	f(s,0,S){
		Pow[s][0]=1;
		f(i,1,N) Pow[s][i]=1ll*Pow[s][i-1]*base%mod[s],ps[i][s]=-1;
	}
	cin>>n>>t;
	build();
	int now=0;
	while(1){
		f_(i,n-1,0){
			change(1,0,(1<<n),n-i-1);
			now^=(1<<i);
			if(bit(now,i)==1) break;
		}
		do_it(now);
		if(now==(1<<n)-1) break;	
	}
	pert(1,n);
}