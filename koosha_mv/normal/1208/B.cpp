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
 
const int N=2002;

int n,a[N],ans=2002,p,s,k;
map<int,int> mark,t;

void coppy(){
	t.clear();
	for(auto u:mark)
		t[u.F]=u.S;
	s=p;
}

int main(){
	cin>>n;
	f(i,0,n){ cin>>a[i]; mark[a[i]]++; if(mark[a[i]]==2) p++;}
	f(i,0,n){
		coppy();
		k=i-1;
		for(int j=i;j<n && s;j++){
			t[a[j]]--;
			if(t[a[j]]==1) s--;
			k=j;
		}
		if(s) break;
		else minm(ans,k-i+1);
	}
	cout<<ans;
}