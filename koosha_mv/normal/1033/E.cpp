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
const int N=610;
int n,a,x,c,v1,v2,mark[N],masir[N],s;
vector<int> v,b1,b2,g[N],ans1,ans2;
void del(int x){
	int l=0,r=v.size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(v[mid]<=x)
			l=mid;
		else
			r=mid;
	}
	v.erase(v.begin()+l);
}
bool check(int x,int y){
	if(y==0) return 1;
	cout<<"? "<<y+1<<endl;
	cout<<x<<" ";
	print(v,y)
	cin>>a;
	if(y==1) c=0;
	else{
		cout<<"? "<<y<<endl;
		print(v,y);
		cin>>c;
	}
	return (a==c);
}
void dfs(int x,int dist){
	del(x);
	if(dist%2) b1.pb(x);
	else b2.pb(x);
	while(1){
		if(check(x,v.size())) break;
		int l=-1,r=v.size()-1,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(check(x,mid+1)) l=mid;
			else r=mid;
		}
		g[x].pb(v[r]);
		g[v[r]].pb(x);
		dfs(v[r],dist+1);
	}
}
void Get_path(int x,int par,int dist,int u){
	mark[dist]=x;
	if(x==u){
		f(i,0,dist+1) masir[i]=mark[i];
		s=dist+1;
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par)
			Get_path(g[x][i],x,dist+1,u);
	}
}
bool check2(int x,int y,vector<int> m){
	cout<<"? "<<y+1<<endl;
	cout<<x<<" ";
	print(m,y)
	cin>>a;
	if(y==1) c=0;
	else{
		cout<<"? "<<y<<endl;
		print(m,y);
		cin>>c;
	}
	return (a==c);
}
void check1(vector<int> m){
	int l=0,r=m.size(),mid,an;
	while(l+1<r){
		mid=(l+r)/2;
		cout<<"? "<<mid+1<<endl;
		print(m,mid+1);
		cin>>a;
		if(a==0) l=mid;
		else r=mid;
	}
	if(r==m.size()) return ;
	an=r;
	l=-1,r=an;
	while(l+1<r){
		mid=(l+r)/2;
		if(check2(m[an],mid+1,m)) l=mid;
		else r=mid;
	}
	v1=m[r],v2=m[an];
	return ;
}
int main(){
	cin>>n;
	f(i,1,n+1) v.pb(i);
	while(v.size()){
		b1.clear(),b2.clear();
		dfs(v[0],0);
		check1(b1);
		check1(b2);
		if(v1!=0){
			Get_path(v1,0,0,v2);
			cout<<"N "<<s<<endl;
			print(masir,s);
			return 0;
		}
		f(i,0,b1.size()) ans1.pb(b1[i]);
		f(i,0,b2.size()) ans2.pb(b2[i]);
	}
	cout<<"Y "<<ans1.size()<<endl;
	print(ans1,ans1.size());
}