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
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int Max=2e5+9,N=4e5+99,sq=440;

int n,m,cnt,ans,Te,a[N],lt[N],X[N],Y[N],g[sq][sq];

void Add(int x,int val){
	cnt+=val;
	int u=X[x],v=Y[x];
	if(u+v<sq){
		if(val==1){
			lt[x]=Te;
			f(i,Te,Te+u){
				g[u+v][i%(u+v)]+=val;
			}
		}
		else{
			f(i,lt[x],lt[x]+u){
				g[u+v][i%(u+v)]+=val;
			}
		}
	}
	else{
		if(val==1){
			lt[x]=Te;
			for(int Time=Te;Time<m;Time+=u+v)
				a[Time]++,a[Time+u]--;
		}
		else{
			for(int Time=lt[x];Time<m;Time+=u+v){
				a[Time]--,a[Time+u]++;
			}
			if((Te-lt[x])%(u+v)<=u  && (Te-lt[x])%(u+v)!=0){
				a[Te]--;
			}
		}
	}
}
int calc(){
	int ans=0;
	f(i,1,sq)
		ans+=g[i][Te%i];
	return ans;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,0,n){
		cin>>X[i]>>Y[i];
		minm(X[i],Max);
		minm(Y[i],Max);
	}
	f(i,0,m){
		int t,x;
		cin>>t>>x;
		if(i) a[i]+=a[i-1];
		Add(--x,t==1 ? 1 : -1);
		cout<<cnt-(a[i]+calc())<<'\n';
		Te++;
	}
}