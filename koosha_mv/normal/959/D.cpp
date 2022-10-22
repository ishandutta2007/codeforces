#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e5+3,m=2e6;
int mark[m],n,x,a[N],k;
vector<int> prime[m],p;
int main(){
	f(i,2,m){
		if(prime[i].size()==0){
			p.pb(i);
			prime[i].pb(i);
			for(int j=i;j<m;j+=i)
				prime[j].pb(i);
		}
	}
	cin>>n;
	f(i,0,n) gett(a[i]);
	f(i,0,n){
		k=0;
		f(j,0,prime[a[i]].size()){
			if(mark[prime[a[i]][j]]==1){
				k=i;
				break;
			}
		}
		if(k>0) break;
		f(j,0,prime[a[i]].size()){
			for(int l=prime[a[i]][j];l<m;l+=prime[a[i]][j])
				mark[l]=1;
		}
	}
	if(k==0) k=n+2;
	f(i,a[k]+1,m){
		if(mark[i]==0){
			a[k]=i;
			break;
		}
	}
	f(j,0,prime[a[k]].size()){
		for(int l=prime[a[k]][j];l<m;l+=prime[a[k]][j])
			mark[l]=1;
	}
	k++;
	for(int i=0;k<n;i++){
		if(!mark[p[i]])
			a[k++]=p[i];
	}
	f(i,0,n) cout<<a[i]<<" ";
	 
}