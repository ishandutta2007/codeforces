#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
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

const int N=5e5+99;

int n,t,x,u,v,p,a[N],ans1[N],ans2[N],pr[N],mark[N];

void make(){
	f(i,2,N)
		if(!mark[i]){
			pr[p++]=i;
			for(int j=i*2;j<N;j+=i)
				mark[j]=1;
		}
}

int main(){
	make();
	cin>>n;
	f(i,0,n){
		vector<int> v;
		gett(x);
		for(int j=0;pr[j]*pr[j]<=x;j++){
			u=pr[j];
			if(x%u==0){
				v.pb(u);
				while(x%u==0)
					x/=u;
			}
		}
		if(x>1)
			v.pb(x);
		if(v.size()==1) ans1[i]=ans2[i]=-1;
		else{
			u=1;
			f(i,1,v.size())
				u=u*v[i];
			ans1[i]=u,ans2[i]=v[0];
		}
	}
	f(i,0,n)
		printf("%d ",ans1[i]);
	cout<<'\n';
	f(i,0,n)
		printf("%d ",ans2[i]);
}