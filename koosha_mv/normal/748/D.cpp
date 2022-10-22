#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define Add(x,y) x=(x+y)%mod
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

const int N=1e5+9,Mx=10005;

int k,n,ans,mx;
vector<string> v[N];
map<string,queue<int> > mark;  

int main(){
	cin>>k>>n;
	f(i,0,k){
		int x;
		string s;
		cin>>s>>x;
		v[x+Mx].pb(s);
	}
	f_(i,N-1,0){
		f(j,0,v[i].size()){
			string s=v[i][j];
			if(mark[s].size() && i+mark[s].front()-Mx>=0){
				string t=s;
				reverse(t.begin(),t.end());
				if(s==t){
					maxm(mx,Mx-i);
				}
				ans+=i+mark[s].front()-Mx;
				mark[s].pop();
			}
			else{
				reverse(s.begin(),s.end());
				mark[s].push(i-Mx);
			}
		}
	}
	for(auto u : mark){
		if(u.S.size()){
		   string s=u.F;
		   reverse(s.begin(),s.end());
		   if(s==u.F) maxm(mx,u.S.front());
		}
	}
	cout<<ans+mx;
}