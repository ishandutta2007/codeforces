#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,t,p1=0,p2;
string s,ans;
int main(){
	cin>>t;
	f(q,0,t){
		p1=-1,p2=-1;
		cin>>n;
		cin>>s;
		f(i,0,n){
			if((s[i]-'0')%2==1){
				if(p1==-1)
					p1=i;
				else{
					p2=i;
					break;
				}
			}
		}
		ans="";
		if(p2==-1) cout<<-1<<endl;
		else{
			f(i,p1,p2+1)
				ans+=s[i];
		}
		cout<<ans<<endl;
	}	
}