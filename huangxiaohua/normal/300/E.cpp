#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000000

int i,j,k,n,m,a[N+500],t;
ll res=1,ans,tmp,l,r,md,t2;
bool p[N+500];
vector<int> v;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int rd()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void init() {
	for(i=2;i<=N;i++) {
		if(!p[i]){v.push_back(i);}
		for(auto j:v){
			if(1ll*i*j>N){break;}
			p[i*j]=1;
		}
	}
}

ll chk(ll x,ll y){
	l=0;r=2e16;ans=2e16;
	while(l<=r){
		tmp=0;md=(l+r)>>1;t2=md;
		while(t2){
			tmp+=t2/x;t2/=x;
		}
		if(tmp>=y){ans=min(ans,md);r=md-1;}
		else{l=md+1;}
	}
	return ans;
}

int main(){
	init();
	t=rd();
	while(t--){
		k=rd();a[k]++;
	}
	for(i=N;i>=1;i--){
		a[i]+=a[i+1];
	}
	for(auto i:v){
		tmp=0;
		for(ll j=i;j<=N;j*=i){
			for(k=j;k<=N;k+=j){
				tmp+=a[k];
			}
		}
		res=max(res,chk(i,tmp));
	}
	printf("%lld",res);
}