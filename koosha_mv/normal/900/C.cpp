#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,a[200099],g,mx=-10,an,s[3],ans[200099];
int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	f(i,1,n+1){
		if(a[i]<s[2] && a[i]>s[1]){
			ans[s[2]]++;
		}
		if(a[i]>s[2]) ans[a[i]]--;
		s[0]=a[i];
		sort(s,s+3);
	}
	f_(i,n,1){
		if(ans[i]>=mx ){
			mx=ans[i],an=i;
		}
	}
	cout<<an;
}