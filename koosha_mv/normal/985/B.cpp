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
const int N=3e5+99;
ll n,m,mark[N],ans;
string s[N];
int main(){
	Get(n,m);
	f(i,0,n){
		cin>>s[i];
		f(j,0,m)
			if(s[i][j]=='1') mark[j]++;
	}
	f(i,0,n){
		ans=1;
		f(j,0,m){
			if(s[i][j]=='1' && mark[j]==1)
				ans=0;
		}
		if(ans){cout<<"YES";return 0;}
	}
	cout<<"NO";
}