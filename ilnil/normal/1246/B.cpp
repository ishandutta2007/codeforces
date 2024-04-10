#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mo=1e9+7,mo2=998244353;
int n,k,a;
int c[N];
int p[N],ps;
vector<P>d[N];
ll ans,aa;
bool b[N];
void go(ll s,int x,int sz,vector<P>&d){
	if(x==sz){
		ll s2=aa/s;
		if(s<=1e5&&s2<=1e5){
			if(s==s2)ans+=(ll)c[s]*(c[s]-1);
			else ans+=(ll)c[s]*c[s2];
		}
		return;
	}
	fo(i,0,d[x].se){
		go(s,x+1,sz,d);
		s*=d[x].fi;
	}
}
int main(){
	cin>>n>>k;
	fo(i,1,n)scanf("%d",&a),c[a]++;
	int a=pow(1e10,1./k);
	for(;(long double)pow(a+1,k)<=1e10;)++a;
	fo(i,2,a){
		if(!b[i])p[++ps]=i,d[i].push_back(P(i,1));
		for(int j=1,u;(u=i*p[j])<=a;++j){
			b[u]=1;
			if(i%p[j]==0){
				d[u]=d[i];
				d[u][d[u].size()-1].se++;
				break;
			}
			d[u]=d[i];
			d[u].push_back(P(p[j],1));
		}
	}
	fo(i,1,a){
		aa=1;
		fo(j,1,k)aa*=i;
		fo(j,0,d[i].size()-1)
			d[i][j].se*=k;
		go(1,0,d[i].size(),d[i]);
	}
	cout<<ans/2;
}