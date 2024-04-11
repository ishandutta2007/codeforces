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
 
const int N=5e5+9,d[4][4]={8,9,1,13,
3,12,7,5
,0,2,4,11
,6,10,15,14};

int n,t,p;

int calc(int x,int y){
	p=n/4;
	return x/4*p+(y/4);
}
int main(){
	cin>>n;
	f(i,0,n){
		f(j,0,n)
			cout<<d[i%4][j%4]+calc(i,j)*16<<" ";
		cout<<endl;
	}
}