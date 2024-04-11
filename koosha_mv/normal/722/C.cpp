#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll p[100099],a[100099],f1[2][100099],ans[100099],k,t,n;
int main(){
	cin>>n;
	f(i,1,n+1){cin>>p[i];p[i]+=p[i-1],f1[0][i]=i-1,f1[1][i]=i;}
	f(i,1,n+1) cin>>a[i];
	f_(i,n,1){
		k=p[f1[1][a[i]]]-p[f1[0][a[i]]];
		f1[1][f1[0][a[i]]]=f1[1][a[i]];
		f1[0][f1[1][a[i]]+1]=f1[0][a[i]];
		ans[i-1]=max(ans[i],k);
	}
	f(i,1,n+1)
		cout<<ans[i]<<endl;
}