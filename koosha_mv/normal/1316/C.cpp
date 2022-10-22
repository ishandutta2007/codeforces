#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e6+9;
int n,m,p,a[N],b[N],s,p1=-1,p2=-1,x;
int main(){
	cin>>n>>m>>p;
	f(i,0,n){
		gett(x);
		if(x%p!=0 && p1==-1){p1=i;}
	}
	f(i,0,m){
		gett(x);
		if(x%p!=0 && p2==-1){p2=i;break;}
	}
	cout<<(p1+p2);
}