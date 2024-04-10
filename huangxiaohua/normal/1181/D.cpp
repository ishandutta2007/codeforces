#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[600500];
ll res[600500],lim[600500],tmp,l,r,md,ans,su[600500],k,i,j,n,m,t,a[600500],sum,it,f[600500];

struct sb{
	int id;
	ll a;
	bool operator<(const sb x)const{return a<x.a;}
}s[600500];

void add(int x){
	for(;x<=n;x+=(-x&x)){f[x]++;}
}

int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

int main(){
	scanf("%lld%lld%lld",&m,&n,&t);
	for(i=1;i<=m;i++){
		scanf("%lld",&k);
		a[k]++;
	}
	for(i=1;i<=n;i++){
		v[a[i]].push_back(i);
	}
	for(i=0;i<=500100;i++){
		sum+=v[i].size();
		su[i]=v[i].size();
		lim[i]=sum;
		if(i){lim[i]+=lim[i-1];su[i]+=su[i-1];}
	}
	for(i=1;i<=t;i++){
		scanf("%lld",&s[i].a);s[i].a-=m;
		s[i].id=i;
	}
	sort(s+1,s+t+1);
	for(auto i:v[0]){
		add(i);
	}
	for(i=1;i<=t;i++){
		while(it<=500005&&lim[it]<s[i].a){
			it++;
			for(auto i:v[it]){
				add(i);
			}
		}
		if(!it){
			tmp=s[i].a;
		}
		else{
			tmp=(s[i].a-lim[it-1]);
		}
		tmp%=su[it];
		if(!tmp){tmp=su[it];}
		l=1;r=n;ans=1145141919;
		while(l<=r){
			md=(l+r)>>1;
			k=get(md);
			if(k==tmp){
				ans=min(ans,md);
				r=md-1;continue;
			}
			if(k<tmp){
				l=md+1;
			}
			else{
				r=md-1;
			}
		}
		res[s[i].id]=ans;
	}
	for(i=1;i<=t;i++){
		printf("%lld\n",res[i]);
	}
}