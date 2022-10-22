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
 
const int N=2500,a[4]={0,1,0,2};
 
int n,t,u,v,x,c,ans,lg=10,last=-1,mark[N],an[20],p[N];
vector<int> vans;
 
int ask(int x,int y,int s){
	if(x<1 || y<1 || x>n || y>n || x==y) cout<<s<<endl;
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>c;
	return c;
}
bool is_bit(int x,int y){
	return x%(1<<(y+1))>=(1<<y);
}
bool check_bit(int x,int y){
	if(x==an[y]) return 1;
	return (is_bit(ask(x,an[y],1),y)==0);
}
void solve(int x){
	while(1){
		u=rand()%n+1,v=rand()%n+1;
		while(u==v)
			u=rand()%n+1,v=rand()%n+1;
		if(!is_bit(ask(u,v,2),x)){
			an[x]=u;
			break;
		}
	}
}
 
int main(){
	srand(time(NULL));
	cin>>n;
	f(i,0,n) p[i]=i+1;
	random_shuffle(p,p+n);
	f_(i,10,0)
		solve(i);
	f(i,0,n){
		if(last==-1 || ask(p[i],last,3)<(1<<(lg+1)))
			while(lg>=0 && check_bit(p[i],lg)){
				lg--;
				last=p[i];
			}
		if(lg==-1){
			ans=p[i];
			break;
		}
	}
	f(i,1,n+1){
		if(i==ans)
			vans.pb(0);
		else
			vans.pb(ask(ans,i,4));
	}
	cout<<"! ";
	f(i,0,n) cout<<vans[i]<<" ";
}