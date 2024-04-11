#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=3e5+9;
int n,t,a[3000],k,pr[100],ans[1005],g[10005],cnt;
vector<int> p;
int main(){
	f(i,2,34){
		n=1;
		f(j,2,i)
			if(i%j==0)
				n=0;
		if(n) pr[i]=k++;
	}
	cin>>t;
	while(t--){
		cnt=0;
		cin>>n;
		f(i,0,n) cin>>a[i];
		f(i,0,n){
			k=0;
			f(j,2,a[i]){
				if(a[i]%j==0){
					k=1;
					ans[i]=pr[j];
					break;
				}
			}
			if(k==0){ans[i]=11;}
		}
		f(i,0,12) g[i]=0;
		f(i,0,n){
			if(g[ans[i]]==0) g[ans[i]]=++cnt;
		}
		cout<<cnt<<endl;
		f(i,0,n) cout<<g[ans[i]]<<" ";
		cout<<endl;
	}
}
// owerflow int long long