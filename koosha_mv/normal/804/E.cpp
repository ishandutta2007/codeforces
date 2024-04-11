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

const int N=1e6+99,d=10;

int n,t,mv,a[N];
vector<pair<int,int> > ans;
vector<int> v[N];
vector<pair<int,int> > s[d],e[d];

void reset(){
	f(i,0,10)
		a[i]=i;
}	
bool apply(vector<pair<int,int> > v){
	f(i,0,v.size())
		swap(a[v[i].F],a[v[i].S]);
	f(i,0,d)
		if(a[i]!=i)
			return 0;
	return 1;
}
void make1(int x){
	vector<pair<int,int> > v;
	f(i,0,x)
		f(j,0,i)
			v.pb(mp(j,i));
	while(1){
		random_shuffle(v.begin(),v.end());
		reset();
		if(apply(v)){
			s[x]=v;
			return ;
		}
	}
}
void make2(int u,int x){
	vector<pair<int,int> > v;
	f(i,0,u)
		f(j,u,u+x)
			v.pb(mp(i,j));
	while(1){
		random_shuffle(v.begin(),v.end());
		reset();
		if(apply(v)){
			f(i,0,v.size()){
				e[x].pb(mp(v[i].F,v[i].S-u));
			}
			return ;
		}
	}
}
void solve(vector<int> v){
	int m=v.size();
	f(i,0,s[m].size())
		ans.pb(mp(v[s[m][i].F],v[s[m][i].S]));	
}
void merge(vector<int> v,vector<int> u){
	int m=u.size();
	f(i,0,e[m].size())
		ans.pb(mp(v[e[m][i].F],u[e[m][i].S]));	
}

int Main(){
	cin>>n;
	f(i,0,n)
		a[i]=i;
	if(n%4>1) return cout<<"NO",0;
	cout<<"YES"<<'\n';
	mv=n%4;
	f(i,0,n){
		if(i==n-1 && mv)
			v[i/4-1].pb(i);
		else
			v[i/4].pb(i);
	}
	f(i,0,n/4)
		solve(v[i]);
	f(i,0,n/4)
		f(j,i+1,n/4)
			merge(v[i],v[j]);
	f(i,0,ans.size()){
		cout<<ans[i].F+1<<" "<<ans[i].S+1<<'\n';
		swap(a[ans[i].F],a[ans[i].S]);
	}
}

int main(){
	srand(time(NULL));
	make1(4);
	make1(5);
	make2(4,4);
	make2(4,5);
	
	Main();
}