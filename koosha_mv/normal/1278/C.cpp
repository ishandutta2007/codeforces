#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,t,mark[500011],a[200009],sump1[100009],sum,gh,ab,e=2e5+2,mn,fa;
int main(){
	cin>>t;
	f(sal,0,t){
		f(i,e-2*n,e+2*n) mark[i]=0;
		cin>>n;gh=0,ab=0;
		f(i,1,2*n+1){
			cin>>a[i];
			if(a[i]==1) ab++;
			else gh++,a[i]=-1;
		}
		fa=ab-gh;
		sump1[n+1]=0;
		f_(i,n,1){
			sump1[i]=sump1[i+1]+a[i];
			mark[sump1[i]+e]=max(mark[sump1[i]+e],i);
		}
		mark[e]=n+1;
		sum=0;mn=1e9;
		if(mark[fa+e]>0) mn=n-mark[fa+e]+1;
		f(i,n+1,2*n+1){
			sum+=a[i];
			if(mark[((fa-sum))+e]!=0)
				mn=min(mn,i-mark[((fa-sum))+e]+1);
		}
		cout<<mn<<endl;
	}
}