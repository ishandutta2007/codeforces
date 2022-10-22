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
#define PI 3.14159265

const int N=5e5+99;

int t,a[N];
double n;

int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		n=n*2.0;
		double deg=180-((n-2)*180.0/double(n));
		double now=-90.0,ans=0;
		f(i,0,n/2){
			now=now+deg;
			double param, result;
  			param = now;
 		 	result = cos (param*PI/180);
			ans+=result;
		}
		printf("%.9f\n",ans);
	}
}