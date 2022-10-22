#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll m,n,p1,p2,o=1,h,ans=1,k,a[100099];
int main(){
	cin>>n>>m>>k;
	f(i,0,m) cin>>a[i];
	if(a[0]%k==0) o=a[0]-k+1;
	else o=a[0]-((a[p1]-h)%k)+1;
	while(p2<m){
		if(a[p2]-o<k){
			h++;
			p2++;
		}
		else{
			ans++;
			p1=p2;
			if(((a[p1]-h)%k)==0)
				o=a[p1]-k+1;
			else
				o=a[p1]-((a[p1]-h)%k)+1;
		}
	}
	cout<<ans;
}