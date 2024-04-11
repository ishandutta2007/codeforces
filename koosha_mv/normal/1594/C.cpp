#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=1e6+99;

int n,t,a[N];
string s;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int mv=0;
		char c;
		cin>>n>>c>>s;
		f(i,0,n){
			if(s[i]!=c) mv=1;
			a[i+1]=(s[i]!=c);
		}
		if(!mv) cout<<0<<endl;
		else{
			mv=0;
			f(i,1,n+1){
				int ck=0;
				for(int j=i;j<=n;j+=i)
					if(a[j])
						ck=1;
				if(ck==0) mv=i;
			}
			if(mv) cout<<1<<endl<<mv<<endl;
			else cout<<2<<endl<<n<<" "<<n-1<<endl;
		}
	}
}