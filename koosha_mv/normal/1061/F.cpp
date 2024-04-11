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

int n,u,v,k,root,depth;
vector<int> path;
string s;

bool ask(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cin>>s;
	return (s=="Yes");
}
void find_depth(){
	int e=1;
	f(i,1,20){
		e=e*k;
		if(e>n){ depth=i; return ; }
	}
}
void Get_dist(){
	f(i,1,n+1)
		if(i!=u && i!=v && ask(u,i,v))
			path.pb(i);
}
bool check(int x){
	int s=0;
	f(i,0,path.size())
		s+=ask(x,path[i],u);
	if(s==depth-1)
		return 1;
	return 0;
}
void solve(){
	f(i,0,path.size())
		if(check(path[i])){
			cout<<"! "<<path[i]<<endl; 
			return ;
		}
}
void mv(){
	f(q,0,55){
		u=rand()%n+1,v=rand()%n+1;
		while(v==u) v=rand()%n+1;
		path.clear(),Get_dist();
		if(path.size()==depth*2-3){
			solve();
			return ;
		}
	}
}

int main(){
	srand(time(NULL));
	cin>>n>>k;
	find_depth();
	mv();
}