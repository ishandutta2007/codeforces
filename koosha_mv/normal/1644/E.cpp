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
#define int ll

const int N=1e6+99;

int n,t,ans,sx,sy,a[N],L[N],R[N];
string s;

void Main(){
	vector<pair<int,int> > vec;
	ans=0;
	cin>>n>>s;
	if(s[0]=='D'){
		f(i,0,s.size()){
			if(s[i]=='D') s[i]='R';
			else s[i]='D';
		}
	}
	string p;
	sx=n-1,sy=n-1;
	f(i,0,s.size()){
		if(s[i]=='D') sx--;
		else sy--;
	}
	f(i,0,s.size()){
		if(s[i]!='R'){
			ans+=i;
			f(j,i,s.size()){
				p+=s[j];
			}
			s=p;
			break;
		}
	}
	if(p.size()==0){
		cout<<n<<endl;
		return ;
	}
	int now=0,x=0,cnt=0;
	f(i,0,s.size()){
		if(s[i]=='R'){
			now++;
			L[now]=x;
		}
		else{
			x++;
		}
		R[now]=x;
	}
	f(i,0,now+1){
		vec.pb({L[i],1});
		vec.pb({R[i]+sx+1,-1});
		L[i]=0,R[i]=0;
	}
	sort(all(vec));
	f(i,0,vec.size()-1){
		cnt+=vec[i].S;
		ans+=(vec[i+1].F-vec[i].F)*(cnt+sy);
	}
	cout<<ans<<endl;
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}