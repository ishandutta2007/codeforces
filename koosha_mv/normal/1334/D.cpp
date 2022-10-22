#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=4e5+9;
int n,q,t,a[N],ans[N],cnt;
ll sum,l,r,s1,s;
void generate(int x){
	if(x==n){
		ans[cnt++]=1;return ;}
	f(i,x+1,n+1)
		ans[cnt++]=x,ans[cnt++]=i;
}
int main(){
	cin>>q;
	while(q--){
		cin>>n>>l>>r;
		sum=0;
		f(i,1,n+1){
			sum+=1ll*(n-i)*2;
			sum+=(i==n);
			if(sum>=l){
				s=i,s1=sum-1ll*((n-i)*2)-(i==n);break;
			}
		}
		sum=0;
		f(i,1,n+1){
			sum+=(n-i)*2;
			sum+=(i==n);
			if(sum>=r){
				t=i;break;
			}
		}
		cnt=0;
		f(i,s,t+1)
			generate(i);
		f(i,l-s1-1,r-s1)
			cout<<ans[i]<<" ";
	}
}