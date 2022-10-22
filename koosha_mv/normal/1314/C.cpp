#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
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

const int N=1005;
const ll Mx=1e18+9;

int n,m,a[N],lcp[N][N];
ll k,dp[N][N];
string s;
vector<pair<int,int> > v;

bool cmp(pair<int,int> i,pair<int,int> j){
	if((i.F+lcp[i.F][j.F]>=i.S) || (j.F+lcp[i.F][j.F]>=j.S)){
		return i.S-i.F<j.S-j.F;
	}
	return s[i.F+lcp[i.F][j.F]]<s[j.F+lcp[i.F][j.F]];
}
void make(){
	f_(i,n-1,0){
		lcp[i][i]=n-i;
		f_(j,n-1,i+1){
			if(s[i]!=s[j]) lcp[i][j]=0;
			else lcp[i][j]=lcp[i+1][j+1]+1;
			lcp[j][i]=lcp[i][j];
		}
	}
	f(i,0,n)
		f(j,i+1,n+1)
			v.pb(mp(i,j));
	sort(v.begin(),v.end(),cmp);	
}
bool check(int l,int r){
	f(i,0,n+2)
		f(j,0,n+2)
			dp[i][j]=0;
	dp[n][0]=1;
	f_(i,n-1,0){
		int j=-1;
		if(l+lcp[l][i]>=r || (i+lcp[l][i]!=n && s[l+lcp[l][i]]<s[i+lcp[l][i]])){
			j=i+min(lcp[l][i],r-l)+1;
			f(k,1,m+1)
				dp[i][k]=dp[j][k-1];
		}
		f(k,0,m+1){
			if(i!=0) dp[i][k]+=dp[i+1][k];
			minm(dp[i][k],Mx);
		}
	}
	return dp[0][m]>=k;
}
void solve(){
	int l=0,r=v.size();
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(v[mid].F,v[mid].S)) l=mid;
		else r=mid;
	}
	f(i,v[r].F,v[r].S)
		cout<<s[i];
}

int main(){
	cin>>n>>m>>k>>s;	
	make();
	solve();
}