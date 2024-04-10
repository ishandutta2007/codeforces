#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,x,y;
ll sb[100500];
struct sb1{
	int x,y;
	ll w;
}s;
vector<sb1> res;

int main(){
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&k);
		sb[x]+=k;
		sb[y]-=k;
	}
	j=1;
	for(i=1;i<=n;i++){
		while(sb[i]>0){
			if(sb[j]>=0){j++;continue;}
			s.x=i;
			s.y=j;
			s.w=min(sb[i],-sb[j]);
			res.push_back(s);
			sb[i]-=s.w;
			sb[j]+=s.w;
		}
	}
	printf("%d\n",res.size());
	for(auto s:res){
		printf("%d %d %lld\n",s.x,s.y,s.w);
	}
}