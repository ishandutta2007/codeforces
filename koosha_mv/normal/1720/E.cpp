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

const int N=505;

int n,k,dif,ps[N],a[N][N],L[N*N],R[N*N],mark[N*N];
vector<int> vec[N];

void do_it(int sx,int sy){
	f(i,0,N) ps[i]=0,vec[i].clear();
	f(i,0,N*N) L[i]=n+1,R[i]=0;
	int tx=sx,ty=sy,len=0;
	while(tx<n && ty<n){
		tx++,ty++,len++;
	}

	f(i,1,n+1){
		f(j,1,n+1){
			int col=a[i][j];
			if(i<sx || j<sy || tx<i || ty<j){
				maxm(R[col],n+1);
			}
			else{
				minm(L[col],min(i-sx,j-sy));
				maxm(R[col],len-min(tx-i,ty-j));
			}
		}
	}
	f(i,1,n*n+1){
		vec[L[i]].pb(R[i]);
	}
	f_(i,len,0){
		for(auto x : vec[i]){
			ps[x]++;
		}
		int sum=0;
		f(j,i,len+1){
			sum+=ps[j];
			if(dif-sum==k-1 || dif-sum==k){
				cout<<1<<'\n';
				exit(0);
			}
		}
	}
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f(i,1,n+1){
		f(j,1,n+1){
			cin>>a[i][j];
			if(!mark[a[i][j]]){
				dif++;
				mark[a[i][j]]=1;
			}
		}
	}
	if(dif<=k) return cout<<k-dif<<'\n',0;
	f(i,1,n+1){
		do_it(i,1);
	}
	f(i,2,n+1) do_it(1,i);
	cout<<2;
}