#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
ll n,t,m,a[3],b,c,ans;
int main(){
	cin>>t;
	f(q,0,t){
		ans=0;
		cin>>a[0]>>a[1]>>a[2];
		f(i,0,3){
			if(a[i]>0) a[i]--,ans++;
		}
		sort(a,a+3);
		swap(a[0],a[2]);
		if(a[0]>0 && a[1]>0) ans++,a[0]--,a[1]--;
		if(a[0]>0 && a[2]>0) ans++,a[0]--,a[2]--;
		if(a[1]>0 && a[2]>0) ans++,a[1]--,a[2]--;
		if(a[0]>0 && a[1]>0 && a[2]>0) ans++;
		cout<<ans<<endl;
	}
}