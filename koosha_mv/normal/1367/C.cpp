#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,k,t,ans,last,a[N];
string s;

int main(){
	cin>>t;
	f(q,0,t){
		ans=0,last=-N;
		cin>>n>>k>>s;
		s=' '+s,n++;
		f(i,1,n) a[i]=a[i-1]+(s[i]=='1');
		f(i,1,n){
			//cout<<(s[i]=='1')<<" "<<(i-last>k)<<" "<<(i+k>=n || a[i]==a[i+k])<<endl;
			if(s[i]=='0' && i-last>k && ((i+k>=n && a[i]==a[n-1]) || (i+k<n && a[i]==a[i+k])))
				s[i]='1',ans++;
			if(s[i]=='1')
				last=i;
		}
		cout<<ans<<endl;
	}
}