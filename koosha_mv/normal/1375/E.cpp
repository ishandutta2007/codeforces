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
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1005;

int n,t,c,a[N],b[N],d[N];
pair<int,int> ans[N*N];

int main(){
	cin>>n;
	f(i,1,n+1){ cin>>a[i]; b[i]=a[i]; }
	
	f(i,1,n+1){
		vector<pair<int,int> > v;
		f(j,i+1,n+1)
			if(a[i]>a[j])
				v.pb(mp(a[j],j));
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		f(j,0,v.size())
			ans[c++]=mp(i,v[j].S);
	}
	cout<<c<<endl;
	f(i,0,c)
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}