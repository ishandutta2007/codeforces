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
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,mx=2e8;

int n,t,x,k1,k2,ans;
queue<int> q1,q2;

int main(){
	int x;
	cin>>n;
	cin>>k1;
	f(i,0,k1){ cin>>x; q1.push(x); }
	cin>>k2;
	f(i,0,k2){ cin>>x; q2.push(x); }
	for(;ans<mx && q1.size() && q2.size();ans++){
		int u=q1.front(),v=q2.front();
		q1.pop(),q2.pop();
		if(u>v)
			q1.push(v),q1.push(u);
		else
			q2.push(u),q2.push(v);
	}
	if(q1.size() && q2.size()) return cout<<-1,0;
	cout<<ans<<endl;
	cout<<(q1.size() ? 1 : 2);
}