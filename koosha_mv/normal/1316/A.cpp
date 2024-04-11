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
const int N=5e5+9;
ll n,m,t,a[N],x;
int main(){
	cin>>t;
	f(q,0,t){
		ll sum=0;
		cin>>n>>m;
		f(i,0,n){
			cin>>x;
			sum+=x;
		}
		cout<<min(sum,m)<<endl;
	}
}