#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5,mod=1e9+7;
int n,a[N];
string s;
int main(){
	cin>>n;
	f(q,0,n){
		cin>>s;
		int mx=0;
		a[0]=0;
		f(i,1,s.size()+1){
			if(s[i-1]=='L')
				a[i]=a[i-1]+1;
			else
				a[i]=0;
			maxm(mx,a[i]);
		}
		cout<<mx+1<<endl;
	}
}