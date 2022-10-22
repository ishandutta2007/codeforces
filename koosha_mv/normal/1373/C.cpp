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

const int N=5e5+99,inf=1e7+2;

int n,t,cur,p;
ll ans;
string s;

int main(){
	cin>>t;
	while(t--){
		cur=0,ans=0,p=0;
		cin>>s;
		n=s.size();
		f(i,0,inf){
			while(cur!=-1 && p<n){
				if(s[p]=='+') cur++;
				else cur--;
				p++;
			}
			ans+=p;
			if(cur!=-1) break;
			cur++;
		}
		cout<<ans<<endl;
	}
}