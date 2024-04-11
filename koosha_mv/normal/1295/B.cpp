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
const int N=1e6+9;
ll n,t,x,e=2e5+2,ans,cnt;
string s;
map<ll,ll> mark;
int main(){
	cin>>t;
	f(q,0,t){
		f(i,e-n,e+n+1) mark[i]=0;
		cin>>n>>x>>s;
		cnt=0;
		ans=0;
		f(i,0,n){
			cnt--;
			cnt+=(s[i]=='0')*2;
			mark[e+cnt]++;
		}
		mark[e]++;mark[e+cnt]--;
		if(cnt==0){
			if(x>100002)
				cout<<0<<endl;
			else{
				if(mark[e+x]==0)
					cout<<0<<endl;
				else cout<<-1<<endl;
			}
		}
		else{
			f(i,e-n-1,e+n+2){
				if((x-(i-e))/cnt>=0 && (x-(i-e))/cnt*cnt==(x-(i-e))){
					ans+=mark[i];
				}
			}
			cout<<ans<<endl;
		}
	}
}