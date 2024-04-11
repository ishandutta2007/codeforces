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

const int N=5e5+99;

int n,t,a[N],cnt[20];
ll ans,x;

int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		f(j,0,20)
			if(is_bit(a[i],j))
				cnt[j]++;
	}
	f(i,0,n){
		x=0;
		f(j,0,20)
			if(cnt[j]){
				cnt[j]--;
				x+=(1<<j);
			}
		ans+=1ll*x*x;
	}
	cout<<ans;
}