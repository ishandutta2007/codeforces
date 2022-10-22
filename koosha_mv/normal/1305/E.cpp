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
int n,m,ans[5002],e=1e9,p=15001,t;
int main(){
	cin>>n>>m;
	--n;
	t=(n/2)*(n/2+1)-((n%2==0)*n/2);
	n++;
	if(t<m)
		return cout<<-1,0;
	t-=m;
	f_(i,n,1){
		if(t>=(i-1)/2){
			t-=(i-1)/2;
			ans[i]=e,e-=p;
		}
		else{
			ans[i]=i+2*(t);
			break;
		}
	}
	f(i,1,n+1){
		cout<<ans[i]+(ans[i]==0)*i<<" ";
	}
}