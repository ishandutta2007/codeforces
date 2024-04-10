#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define NO return printf("No"),0
using namespace std;
const int N=(1<<15)+5,mo=1e9+7;
int k,n;
vector<int>a[20];
map<ll,int>ex;
ll sum,su[20];
int fr[N],fr2[N];
int to[N],out[N],in[N];
bool is[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>k;
	fo(i,1,k){
		cin>>n;
		a[i].resize(n);
		fo(j,0,n-1)cin>>a[i][j],su[i]+=a[i][j],ex[a[i][j]]=i;
		sum+=su[i];
	}
	if(sum%k)NO;
	sum/=k;
	fo(i,1,k){
		ll s;
		fo(j,0,a[i].size()-1){
			s=sum-su[i]+a[i][j];
			if(ex[s]){
				int S=1<<i-1;
				bool can=1;
				for(;ex[s]!=i;){
					if(S&(1<<ex[s]-1)){
						can=0;break;
					}
					S|=1<<ex[s]-1;
					s=sum-su[ex[s]]+s;
				}
				if(can&&!fr[S]&&s==a[i][j])fr[S]=a[i][j],is[S]=1;
			}
		}
	}
	fo(i,1,(1<<k)-1)if(!is[i]){
		for(int j=i;j;j=(j-1)&i)
			if(is[j]&&fr[i^j]){
				fr2[i]=i^j;
				is[i]=1;
				break;
			}
	}else fr2[i]=i;
	if(!is[(1<<k)-1])NO;
	printf("Yes\n");
	for(int S=(1<<k)-1;S;){
		ll j=fr[fr2[S]];
		int o=ex[j],*tt;
		out[ex[j]]=j;
		tt=&to[ex[j]];
		j=sum-su[ex[j]]+j;
		for(;ex[j]!=o;){
			*tt=ex[j];
			out[ex[j]]=j;
			tt=&to[ex[j]];
			j=sum-su[ex[j]]+j;
		}
		*tt=o;
		S^=fr2[S];
	}
	fo(i,1,k)in[to[i]]=i;
	fo(i,1,k)printf("%d %d\n",out[i],in[i]);
}