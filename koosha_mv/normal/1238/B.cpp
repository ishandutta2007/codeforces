#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+9;
int t,n,r,a[N],ans,c,x,mark[N];
int main(){
	cin>>t;
	while(t--){
		Gett(n,r);
		c=0;
		f(i,0,n){
			gett(x);
			if(!mark[x]){
				mark[x]=1;
				a[c++]=x;
			}
		}
		sort(a,a+c);
		f(i,0,c+1)
			if(i==c || i*r>=a[c-i-1]){
				printf("%d\n",i);
				break;
			}
		f(i,0,c) mark[a[i]]=0;
	}
}