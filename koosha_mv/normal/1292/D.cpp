#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
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
 
const int N=5005,M=700;
 
int n,c,sans,ans[N],a[N],b[N],p[N],d[N][M];
vector<int> P;
ll res;

void pre(){
	P.pb(0);
	f(i,2,N){
		p[i]^=1;
		if(p[i]){
			P.pb(i);
			p[i]=++c;
			for(int j=2*i;j<N;j+=i)
				p[j]=1;
		}
	}
	f(i,1,N){
		int x=i;
		f(j,0,M)
			d[i][j]=d[i-1][j];
		f(j,2,N){
			while(x%j==0){
				x/=j;
				d[i][p[j]]++;
			}
		}
	}
}
void solve(int l,int r){
	int res=0;
	f_(i,M-1,0){
		int mn=N*N,mx=0;
		f(j,l,r){
			minm(mn,d[j][i]);
			maxm(mx,d[j][i]);
		}
		b[i]=mn;
		res+=mn;
		
		if(mn!=mx || i==0){
			if(res>sans){
				sans=res;
				f(i,0,M) ans[i]=b[i];
			}
			//erorp(mp(l,r));
			//cout<<i<<" : "<<P[i]<<endl;
			break;
		}
	}
}
int dist(int x){
	int res=0;
	f(i,0,M)
		res+=ans[i]+d[x][i];
	f_(i,M-1,0){
		if(ans[i]!=d[x][i]){
			res-=2*min(ans[i],d[x][i]);
			break;
		}
		res-=2*ans[i];
	}
	return res;
}

int main(){
	pre();
	cin>>n;
	f(i,0,n){
		int x;
		gett(x);
		maxm(x,1);
		a[x]++;
	}
	f(i,1,N){
		int sum=0;
		f(j,i,N){
			sum+=a[j];
			if(p[j] && j!=i) break;
			if(sum>=(n+1)/2){
				solve(i,j+1);
				break;
			}
		}
	}
	//eror(sans);
	//f(i,1,10) cout<<P[i]<<" : "<<ans[i]<<endl;
	f(i,1,N)
		res+=1ll*a[i]*dist(i);
	cout<<res<<endl;
}