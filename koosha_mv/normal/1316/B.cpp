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
const int N=5e5+9;
ll n,t,ans;
string s,p,ans1;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>s;
		f(i,0,n){
			p="";
			f(j,i,n)
				p+=s[j];
			if((i+n)%2==1)
				f_(j,i-1,0) p+=s[j];
			else
				f(j,0,i) p+=s[j];
			if(i==0 || p<ans1){
				ans1=p,ans=i+1;
			}
		//	cout<<p<<endl;
		}
		cout<<ans1<<endl<<ans<<endl;
	}
}