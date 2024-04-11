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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,dx[8]={0,1,2,2,2,1,0,0},dy[8]={0,0,0,1,2,2,2,1};

int n,t,x,y;
vector<pair<int,int> > ans;
int main(){
	cin>>n;
	ans.pb(mp(0,0));
	f(i,0,n+1){
		f(j,1,8)
			ans.pb(mp(x+dx[j],y+dy[j]));
		x+=2,y+=2;
	}
	cout<<ans.size()<<endl;
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}