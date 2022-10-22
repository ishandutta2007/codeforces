#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
const int N=2e6;
ll a[N],tedad[N],b[N],tedad2[N],ans1[N],ans;
string binary(ll m,ll k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
	
pair <ll,ll> pa[N];
int main(){
	ll n,cn,tvn=1,k=0;
	string s,s2;
	cin>>n;cn=n;
	while(cn){
		k++;
		cn/=2;
		tvn*=2;
	}tvn/=2;
	ll p=0,ct;
	f(i,0,n){
		cin>>pa[i].first;b[i]=pa[i].first;
		pa[i].second=i;
	}
	sort(pa,pa+n);
	f(i,0,n){
		a[pa[i].second]=i+1;
	}
	ll sum=0;
	f(i,0,n){
		s=binary(a[i],k);p=0;ct=tvn;
		ll t=0,m=tvn*2-a[i],p1=tvn*2;s2=binary(m,k);
		f_(j,k-1,0){
			if(s2[j]=='1'){
				p1-=ct;
				t+=tedad[p1];	
			}
			ct/=2;
		}
		ans1[i]=t;
		ct=tvn;
		f_(j,k-1,0){
			if(s[j]=='1'){
				p+=ct;
				tedad[p]++;
			}
			ct/=2;
		}
	}
	f(i,0,n){
		s=binary(a[i],k);p=0;ct=tvn;
		ll t=0,m=tvn*2-a[i],p1=tvn*2;s2=binary(m,k);
		f_(j,k-1,0){
			if(s2[j]=='1'){
				p1-=ct;
				t+=tedad2[p1];	
			}
			ct/=2;
		}
		ans+=t;
		ct=tvn;
		f_(j,k-1,0){
			if(s[j]=='1'){
				p+=ct;
				tedad2[p]+=ans1[i];
			}
			ct/=2;
		}
	}
	
	
	cout<<ans;
	
}