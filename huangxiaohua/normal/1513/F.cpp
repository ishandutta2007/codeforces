#include<bits/stdc++.h>
using namespace std;
long long res;
set<int> s;
unordered_map<int,int>mp;
priority_queue<pair<int,int> >q;
int i,j,k,n,a[200500],res2;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		res+=abs(k-a[i]);
		if(k>=a[i]){s.insert(a[i]);mp[a[i]]=max(mp[a[i]],k);}
		else{q.push({-k,a[i]});}
	}
	for(auto i:s){
		while(!q.empty()){
			auto [u,v]=q.top();u=-u;
			if(v<=mp[i]){res2=max(res2,(v-max(u,i))*2);q.pop();}
			else{res2=max(res2,(mp[i]-max(u,i))*2);break;}
		}
	}
	printf("%lld",res-res2);
}