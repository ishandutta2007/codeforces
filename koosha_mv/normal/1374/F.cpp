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
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,t,mos,a[N],mark[N];
vector<int> ans;

void op(int x){
	swap(a[x+1],a[x+2]);
	swap(a[x],a[x+1]);
}
void mv(int x){
	int an,mn=N;
	f(i,x,n+1) minm(mn,a[i]);
	f(i,x,n+1)
		if(a[i]==mn){
			an=i;
			break;
		}
	while(an>x+1){
		an-=2;
		op(an);
		ans.pb(an);
	}
	if(an==x+1)
		ans.pb(x),ans.pb(x),op(x),op(x);
}
void solve(){
	ans.clear();
	f(i,1,n-1)
		mv(i);
}

int main(){
	cin>>t;
	f(q,0,t){
		fill(mark,mark+600,0);
		mos=0;
		cin>>n;
		f(i,1,n+1){
			gett(a[i]);
			mark[a[i]]++;
			mos=(mos || (mark[a[i]]>1));
		}
		solve();
		if(a[n-1]>a[n]){
			if(mos){
				int an=n-1;
				while(a[an]>a[an+1]){
					an--;
					op(an);
					ans.pb(an);
				}
				cout<<ans.size()<<endl;
				print(ans,ans.size());
			}
			else cout<<-1<<endl;
		}
		else{
			cout<<ans.size()<<endl;
			print(ans,ans.size());
		}
	}
}