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

const int N=1e6+99,Z=26;

int n,t,a[N],f[Z],nxt[Z],mark[Z];
string s;

int getpar(int x){
	while(nxt[x]>=0) x=nxt[x];
	return x;
}
void Main(){
	int cnt=0;
	cin>>n>>s;
	f(i,0,n){
		int x=s[i]-'a';
		if(nxt[x]==-1){
			cnt++;
			f(j,0,26){
				if(mark[j]==0 && x!=j && (getpar(j)!=x || cnt==Z)){
					nxt[x]=j;
					mark[j]=1;
					break;
				}
			}
		}
		//eror(nxt[x]);
		cout<<char('a'+nxt[x]);
	}
	cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		f(i,0,Z) f[i]=nxt[i]=-1,mark[i]=0;
		Main();
	}
}