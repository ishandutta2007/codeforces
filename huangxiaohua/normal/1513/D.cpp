#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
int i,j,k,m,t,x,n,a[200500];
ll p,res;
struct sb{
	int l,r;ll num;
	bool operator<(const sb x)const{return num>x.num;}
}s;

priority_queue<sb> q;
vector<sb> v[200500];
unordered_map<int,unordered_map<int,bool> >used;

void get(int x){
	int i,j,k,l,r;
	for(l=x-1;l>=1;l--){
		if(used[l][a[x]]){l++;break;}
		if(a[l]%a[x]){l++;break;}
		used[l][a[x]]=1;
	}
	if(!l){l++;}
	for(r=x+1;r<=n;r++){
		if(used[r][a[x]]){r--;break;}
		if(a[r]%a[x]){r--;break;}
		used[r][a[x]]=1;
	}
	if(r==(n+1)){r--;}
	//printf("a%d %d %d\n",x,l,r);
	v[l].push_back({l,r-1,a[x]});
}

int main(){
	//freopen("sb.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&p);
		while(!q.empty()){q.pop();}
		used.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			v[i].clear();
		}
		for(i=1;i<=n;i++){
			get(i);
		}
		res=0;
		for(i=1;i<n;i++){
			for(auto x:v[i]){
				q.push(x);
			}
			//printf("a%d %d\n",i,q.size());
			while(!q.empty()&&q.top().r<i){q.pop();}
			if(q.empty()){res+=p;continue;}
			res+=min(p,q.top().num);
		}
		printf("%lld\n",res);
	}
}