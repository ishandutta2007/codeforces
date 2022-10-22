#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
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

const int N=1e6+99;

int n,m,cnt,a[N],l[2];
string s;
ll ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	f(i,0,s.size()){
		a[i]=(i<n-1 && s[i]!=s[i+1]);
		if(i) a[i]+=a[i-1];
		if(i>1 && s[i]!=s[i-2]) l[i&1]=i;
		if(i==0 || s[i]!=s[i-1]) cnt++;
		if(i==0) ans+=m-1;
		else{
			ans+=1ll*(m-1)*cnt+1ll*(m-1)*(1+i*(s[i]!=s[i-1]));		
			if(i>0 && s[i]==s[i-1]) ans-=m-1;
			else{
				ans-=m-1;
				ans-=a[i-1];
				if(max(l[0],l[1])-2>=0) ans+=a[max(l[0],l[1])-2]; 
			}
		}
	}
	cout<<ans;
}