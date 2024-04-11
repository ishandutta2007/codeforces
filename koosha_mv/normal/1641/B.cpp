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

const int N=505;

int n,t,a[N];
vector<int> T;
vector<pair<int,int>> res;

void solve(vector<int> vec){
	int pos;
	f_(i,vec.size()-2,0){
		if(vec[i]==vec.back()){
			pos=i;
			break;
		}
	}
	T.pb(2*(vec.size()-pos-1));
	int now=pos;
	f_(i,vec.size()-2,pos+1){
		res.pb({now,vec[i]});
		now++;
	}
	vec.pop_back();
	vec.erase(vec.begin()+pos);
	reverse(vec.begin()+pos,vec.end());
	if(vec.size()==0) return ;
	solve(vec);
}
void Main(){
	map<int,int> cnt;
	vector<int> vec;
	res.clear();
	T.clear();
	cin>>n;
	f(i,1,n+1){
		int x;
		cin>>x;
		vec.pb(x);
		cnt[x]++;
	}
	for(auto p : cnt) if(p.S&1){
		cout<<-1<<endl;
		return ;
	} 
	solve(vec);
	reverse(all(T));
	cout<<res.size()<<endl;
	for(auto p : res) cout<<p.F<<" "<<p.S<<endl;
	cout<<T.size()<<endl;
	for(auto x : T) cout<<x<<" "; cout<<endl;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--) Main();
}