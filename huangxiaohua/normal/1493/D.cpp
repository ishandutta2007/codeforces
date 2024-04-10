#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#pragma GCC optimize(2)

unordered_map<int,unordered_map<int,int>> mp;
int i,j,k,n,m,t,a[200500],x,st[205],sn,ans[200500];
ll res=1;

struct sb{
	int x,id;
	bool operator<(const sb a)const{return x>a.x;}
}s;

ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

priority_queue<sb> q[200500];
vector<int> v[200500];
bool used[200500];

int main(){
	for(i=2;i<=200000;i++){
		if(!used[i]){
			for(j=i;j<=200000;j+=i){
				k=j;used[j]=1;
				while(!(k%i)){v[j].emplace_back(i);k/=i;}
			}
		}
	}
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(auto j:v[k]){
			if(!mp[i][j]){a[j]++;}
			mp[i][j]++;q[j].push({mp[i][j],i});
		}
	}
	for(i=1;i<=200000;i++){
		if(a[i]<n){continue;}
		while(1){
			s=q[i].top();
			if(mp[s.id][i]!=s.x){q[i].pop();}
			else{break;}
		}
		ans[i]=q[i].top().x;
		res=res*ksm(i,q[i].top().x);
	}
	while(t--){
		scanf("%d%d",&x,&k);
		for(auto i:v[k]){
			if(!mp[x][i]){a[i]++;}
			st[++sn]=i;
			mp[x][i]++;
			q[i].push({mp[x][i],x});
		}
		while(sn){
			i=st[sn];sn--;
			if(a[i]<n){continue;}
			while(1){
				s=q[i].top();
				if(mp[s.id][i]!=s.x){q[i].pop();}
				else{break;}
			}
			j=q[i].top().x;
			if(j!=ans[i]){res=res*ksm(i,j-ans[i])%M;}
			ans[i]=j;
		}
		printf("%lld\n",res);
	}
}