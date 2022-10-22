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

const int N=1e6+9;

int n,t,k,ans,c[N];;
string s;
string v[N];

int solve(string a,int p){
	int mx=0,t1=0,res=N,e=0;
	f(i,0,a.size()){
		t1+=(a[i]=='1');
		e+=(a[i]=='0');
		minm(res,e-mx+(p-t1));
		maxm(mx,e-t1);
	}
	return res;
}
int main(){
	cin>>t;
	while(t--){
		f(i,0,k) v[i]="",c[i]=0;
		cin>>n>>k>>s;
		int t1=0;
		
		f(i,0,n){
			t1+=(s[i]=='1');
			v[i%k]+=s[i];
			c[i%k]+=(s[i]=='1');
		}
		ans=t1;
		f(i,0,k)
			minm(ans,solve(v[i],c[i])+t1-c[i]);
		cout<<ans<<endl;
	}
}