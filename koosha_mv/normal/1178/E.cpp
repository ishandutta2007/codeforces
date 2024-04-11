#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
string s,ans,ans1,k;
ll sz,l,r,a[100];
int main(){
	cin>>s;
	sz=s.size();
	l=0,r=sz-1;
	while(r-l>2){
		a[0]=a[1]=a[2]=0;
		a[s[r]-'a']++,a[s[l+1]-'a']++,a[s[l]-'a']++,a[s[r-1]-'a']++;
		f(i,0,3){
			if(a[i]>1){
				ans+=char('a'+i);break;
			}
		}
		l+=2,r-=2;
	}
	if(sz%4>=2) k=s[sz/2];
	f_(i,ans.size()-1,0) ans1+=ans[i];
	cout<<ans<<k<<ans1;
}