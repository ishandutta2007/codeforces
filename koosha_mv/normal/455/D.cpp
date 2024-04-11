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

const int N=1e5+99,sq=340;

int n,q,cp,l,r,k,ans,mark[sq][N];
deque<int> v[sq];

void modify(){
	l=(l+ans-1)%n;
	r=(r+ans-1)%n;
	k=(k+ans-1)%n+1;
	if(l>r) swap(l,r);
}
void shift(int x){
	mark[x][v[x].back()]--;
	mark[x+1][v[x].back()]++;
	v[x+1].push_front(v[x].back());
	v[x].pop_back();
}
void del(int x){
	int s=x/sq;
	x%=sq;
	cp=v[s][x];
	mark[s][v[s][x]]--;
	v[s].erase(v[s].begin()+x);
}
void add(int x,int y){
	deque<int> d;
	int s=x/sq;
	x%=sq;
	f(i,0,v[s].size()){
		if(i==x) d.pb(y);
		d.pb(v[s][i]);
	}
	mark[s][y]++;
	v[s]=d;
}
void Add_query(){
	cin>>l>>r;
	modify();
	del(r);
	add(l,cp);
	l=l/sq,r=r/sq;
	f(i,l,r){
		shift(i);
	}
}
void Get_query(){
	cin>>l>>r>>k;
	modify();
	ans=0;
	while(l%sq!=0 && l<=r){
		ans+=(v[l/sq][l%sq]==k);
		l++;
	}
	while(l<=r){
		ans+=(v[r/sq][r%sq]==k);
		if(r%sq==0) break;
		r--;
	}
	l=l/sq,r=r/sq;
	f(i,l,r) ans+=mark[i][k];
	cout<<ans<<endl;
}

int main(){
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		v[i/sq].pb(x);
		mark[i/sq][x]++;
	}
	cin>>q;
	f(i,0,q){
		int type;
		cin>>type;
		if(type==1) Add_query();
		else Get_query();
	}
}