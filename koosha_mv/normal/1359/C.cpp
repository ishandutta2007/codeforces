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

int q,l,r,p,an;
double h,c,t,mid,e,m,ans;

double calc(double x){
	double o=h/x;
	return abs(t-(mid+o));
}

int main(){
	cin>>q;
	while(q--){
		cin>>h>>c>>t;
		mid=(h+c)/2;
		if(mid>=t) cout<<2;
		else{
			ans=1e6;
			e=t-mid;
			h-=mid;
			p=h/e;
			if(p%2) p++;
			for(int i=max(1,p-9);i<p+10;i+=2){
				if(calc(i)<ans) ans=calc(i),an=i;
			}
			cout<<an;
		}
		cout<<endl;
	}
}