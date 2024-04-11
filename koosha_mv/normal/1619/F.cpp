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

const int N=1e6+99;

int n,m,k,t,a[N];

void Main(){
	cin>>n>>m>>k;
	int x=(n+m-1)/m,last=0;
	f(i,0,k){
		int now=n,M=m;
		while(now>0 && (now+m-1)/m==x){
			cout<<x<<" ";
			f(j,0,x){
				cout<<last+1<<" ";
				last=(last+1)%n;
			}
			cout<<endl;
			now-=x;
			m--;
		}
		int mv=last;
		while(now>0){
			cout<<x-1<<" ";
			f(j,0,x-1){
				cout<<mv+1<<" ";
				mv=(mv+1)%n;
			}
			cout<<endl;
			now-=x-1;
			m--;
		}
		m=M;
		cout<<endl;
	}
	return ;
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}	
}