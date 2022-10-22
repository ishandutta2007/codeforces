#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+99;
int n,t,mark[160],mark2[160],ans=1e9,k,p,e;
string s[N],g;
int main(){
	cin>>n;
	f(i,0,n) cin>>s[i];
	f(i,0,s[0].size())
		mark[s[0][i]]++;
	f(i,1,n){
		f(j,0,160) mark2[j]=0;
		f(j,0,s[i].size()){
			mark2[s[i][j]]++;
			if(mark2[s[i][j]]>mark[s[i][j]]) return cout<<-1,0;
		}
	}
	f(i,0,s[0].size()){
		g="";
		g+=s[0][i];
		for(int j=(i+1)%s[0].size();j!=i;j=(j+1)%s[0].size())
			g+=s[0][j];
		k=i;
		f(j,1,n){
			e=0;
			f(l,0,s[0].size()){
				p=0;
				f(h,0,s[0].size())
					if(s[j][(l+h)%s[0].size()]!=g[h])
						p=1;	
				if(p==0){
					k+=l;
					e=1;
					break;
				}
			}
			if(e==0)
				k=1e8;
		}
		minm(ans,k);
	}
	if(ans>1e5) return cout<<-1,0;
	cout<<ans;
}