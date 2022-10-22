#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,sq=448;

int n,t,a[N],mna[N],mxa[N],G[N][sq];
ll ans;
string s;

int calc(int x,int y,int c){ y--; return x/c-y/c; }

void case1(){
	f(i,1,n+1)
		f(j,1,min(a[i]+1,sq)){
			int l=mna[a[i]-j],r=min(mxa[a[i]-j],i-j*sq);
			if(l<=r)
				ans+=calc(i-l,i-r,j);
		}
}
void case2(){
	f(j,1,sq){
		int mx=0;
		f(i,0,n+1)
			maxm(mx,-1*(a[i]-(i/j)));
		f(i,0,n+1)
			ans+=G[a[i]-i/j+mx][i%j]++;
		f(i,0,n+1)
			G[a[i]-i/j+mx][i%j]--;
	}
}

int main(){
	fill(mna,mna+N,N);
	fill(mxa,mxa+N,-1);
	cin>>s;
	n=sz(s);
	mna[0]=mxa[0]=0;
	f(i,1,n+1){
		a[i]=a[i-1];
		if(s[i-1]=='1') a[i]++;
		minm(mna[a[i]],i);
		maxm(mxa[a[i]],i);
	}
	case1();
	case2();
	cout<<ans;
}