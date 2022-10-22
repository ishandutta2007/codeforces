#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+5;
int n,ans[N],cnt;
int main(){
	cin>>n;
	f(i,2,n+1){
		if(ans[i]==0){
			cnt++;
			for(int j=i;j<=n;j+=i)
				ans[j]=cnt;
		}
	}
	f(i,2,n+1) cout<<ans[i]<<" ";
}