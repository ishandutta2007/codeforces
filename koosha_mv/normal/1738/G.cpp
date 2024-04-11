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

const int N=1010;

int n,t,k,f[N],a[N][N],pd[N][N];

void add(int x,int val){
	for(x+=2;x<n+10;x+=(x&-x)){
		maxm(f[x],val);
	}
}
int get(int x){
	int ans=0;
	for(x+=2;x;x-=(x&-x)){
		maxm(ans,f[x]);
	}
	return ans;
}
void Main(){
	cin>>n>>k;
	f(i,1,n+1){
		f(j,1,n+1){
			char c;
			cin>>c;
			a[i][j]=c-'0';
			a[i][j]^=1;
		}
	}
	f_(i,n,1){
		f(j,1,n+1){
			pd[i][j]=get(n-(j+1))+1;
			if(a[i][j]){
				add((n-j),pd[i][j]);
				if(pd[i][j]>=k){
					cout<<"NO"<<'\n';
					return ;
				}
			}
		}
	}
	f(i,0,n+10) f[i]=0;
	f(i,1,n+1){
		f_(j,n,1){
			int x=get(j-1)+1;
			if(x+pd[i][j]<=k){
				a[i][j]=1;
			}
			if(a[i][j]){
				add(j,x);
			}
		}
	}
	cout<<"YES"<<'\n';
	f(i,1,n+1){
		f(j,1,n+1){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,0,n+10) f[i]=0;
	}
}