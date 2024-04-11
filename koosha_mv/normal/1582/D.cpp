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

const int N=1e6+99;

int n,t,a[N],b[N];
ll sum=0;

void solve1(int x){
	int u=a[x],v=a[x+1];
	b[x]=v,b[x+1]=-u;
}
void solve2(int x){
	int id1=x,id2=x+1,id3=x+2;
	if(a[id1]+a[id2]==0){
		swap(id1,id3);
	}
	if(a[id1]+a[id2]==0){
		swap(id2,id3);
	}
	int u=a[id1]+a[id2],v=a[id3];
	b[id1]=v,b[id2]=v;
	b[id3]=-u;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n+1) cin>>a[i];
		if(n&1){
			for(int i=1;i<n-3;i+=2){
				solve1(i);
			}
			solve2(n-2);
		}
		else{
			for(int i=1;i<n;i+=2)
				solve1(i);
		}
		f(i,1,n+1) cout<<b[i]<<" ";
		cout<<endl;
	}
}