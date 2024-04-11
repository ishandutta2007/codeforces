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
 
const int N=305,inf=1e8;
 
int n,r,c,t,last,tnow,p[N];
 
bool check(){
	f(i,1,n)
		if(p[i]==-1)
			return 1;
	return 0;
}
void ask(int l,int r){
	c++;
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>tnow;
 
}
int calc(int x,int y){
	f(i,0,x+1)
		if((x-i*2)==y)
			return i;
}
void solve1(int l,int r,int s){
	last=tnow;
	ask(l,r);
	if((tnow-last+inf)%2==s)
		p[l]=calc(l,tnow-last);
	else
		p[l-1]=t-calc(n-l+1,tnow-last);
	while(c%2 || tnow!=t)
		ask(l,r);
}
void solve2(int l,int r,int s){
	last=tnow;
	ask(l,r);
	if((tnow-last+inf)%2==s)
		p[r]=calc(r,tnow-last);
	else
		p[l-1]=t-calc(n-l+1,tnow-last);
	while(c%2 || tnow!=t)
		ask(l,r);
	
}
void case1(){
	cout<<"! "<<t<<endl;
	exit(0);
}
void case2(){
	while(check()){
		f(i,1,n) 
			if(p[i]==-1)
				solve1(i,i,i%2);
	}
	cout<<"! ";
	f(i,1,n+1)
		cout<<p[i]-p[i-1];
	exit(0);
}
void case3(){
	while(check()){
		if(p[1]==-1)
			solve2(2,3,1);
		f(i,2,n)
			if(p[i]==-1)
				solve2(i-1,i,i%2);
	}
	cout<<"! ";
	f(i,1,n+1)
		cout<<p[i]-p[i-1];
}
 
int main(){
	fill(p,p+N,-1);p[0]=0;
	srand(time(NULL));
	cin>>n>>t;tnow=t,p[n]=t;
	if(n<2) case1();
	if(n%2==0) case2();
	case3();
}