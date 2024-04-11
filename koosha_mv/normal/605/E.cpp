#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
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
#define ld double

const int N=1009;

int n,t,a[N],mark[N];
ld pr[N],dist[N],p[N][N];

ld P(int u){
	if(dist[u] == 0) return 0;
	return (dist[u] + pr[u]) / (1 - pr[u]);
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		f(j,0,n){
			int x;
			cin >> x;
			p[i][j] = x / 100.0;
		}
	}
	f(i,0,n){
		pr[i] = 1;
		if(i != n-1){
			dist[i] = N * N ;
		}
	}
	f(T,0,n){
		int u = -1;
		f(i,0,n){
			if(!mark[i] && (u == -1 || P(i)<P(u))){
				u = i;
			}
		}
		dist[u] = P(u);
		mark[u] = 1;
		f(i,0,n){
			if(!mark[i] && p[i][u] > 0){
				if(dist[i] == N * N) dist[i] = 0;
				dist[i] += pr[i] * p[i][u] * (dist[u] + 1);
				pr[i] = pr[i] * (1 - p[i][u]);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<dist[0];
}