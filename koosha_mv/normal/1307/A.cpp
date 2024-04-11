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
const int N=1009;
ll n,t,d,a[N],ans;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>d;
		ans=0;
		f(i,0,n){
			cin>>a[i];
			if(i==0) ans+=a[i];
			else{
				ans+=min(d/i,a[i]);
				d-=min(d/i,a[i])*i;
			}
		}
		cout<<ans<<endl;
	}
}