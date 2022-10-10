#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
ll read(){
	ll x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

int i,j,k,n,m,T;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		ll p=read(),q=read(),tmp=p,Ans=1;
		if(p%q!=0){cout<<p<<endl;continue;}
		for(i=2;i<=sqrt(q);i++){
			ll a=tmp,b=q;
			while(p%i==0)p/=i,a/=i;
			if(q%i==0){
				ll s=1;
				while(q%i==0)q/=i,s*=i;
				s/=i;
				Ans=max(Ans,a*s);
			}
		}
		if(q!=1){
			ll a=tmp,b=q;
			while(p%q==0)p/=q,a/=q;
			if(q%q==0){
				ll s=q;
				s/=q;
				q/=q;
				Ans=max(Ans,a*s);
			}
		}
		cout<<Ans<<endl;
	}
}