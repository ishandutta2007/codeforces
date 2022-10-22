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
const int N=1e5+9;
ll n,t,ans[N],p[200000],sp;
vector<pair<ll,ll> > v;
ll tavan(ll x,ll y){
	ll o=1;
	f(i,0,y)
		o*=x;
	return o;
}
int main(){
	f(i,2,1e5+9){
		if(ans[i]==0){
			p[sp]=i;
			sp++;
			for(int j=i*2;j<N;j+=i)
				ans[j]=1;
		}
	}
	cin>>t;
	f(q,0,t){
		v.clear();
		cin>>n;
		f(i,0,sp){
			if(n%p[i]==0){
				v.pb(make_pair(p[i],0));
				while(n%p[i]==0){
					n/=p[i];
					v[v.size()-1].second++;
				}
			}
		}
		if(n>1)
			v.pb(make_pair(n,1));
		
		ll ans1=1;
		if(v.size()>=3){
			f(i,0,v.size()-2){
				ans1*=tavan(v[i].first,v[i].second);
			}
			cout<<"YES"<<endl<<ans1<<" "<<tavan(v[v.size()-2].first,v[v.size()-2].second)<<" "<<tavan(v[v.size()-1].first,v[v.size()-1].second)<<endl;
		}
		else{
			if(v.size()==1){
				if(v[0].second>=6)
					cout<<"YES"<<endl<<v[0].first<<" "<<v[0].first*v[0].first<<" "<<tavan(v[0].first,v[0].second-3)<<endl;
				else cout<<"NO"<<endl;
			}
			if(v.size()==2){
				if(v[0].second>=3){
					cout<<"YES"<<endl<<v[0].first<<" "<<tavan(v[0].first,v[0].second-1)<<" "<<tavan(v[1].first,v[1].second)<<endl;
				}
				else{
					if(v[1].second>=3)
						cout<<"YES"<<endl<<v[1].first<<" "<<tavan(v[1].first,v[1].second-1)<<" "<<tavan(v[0].first,v[0].second)<<endl;
					else{ 
						if(v[1].second==2 && v[0].second==2){
							cout<<"YES"<<endl<<v[0].first<<" "<<v[1].first<<" "<<v[0].first*v[1].first<<endl;
						}
						else cout<<"NO"<<endl;
					}
				}
			}
		}
	}
}