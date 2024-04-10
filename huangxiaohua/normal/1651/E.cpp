#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,t1,t2,it,a[6050];
bool vis2[3050],vis[3050];
vector<int> v[3050];
long long res;

void dfs(int x){
	if(vis[x])return;
	a[++it]=x;
	vis[x]=1;
	for(auto i:v[x]){
		dfs(i);
	}
}

void chk(){
	int i,j,k;
	for(i=1;i<=it;i++){
		a[it+i]=a[i];
	}
	
	for(i=2;i<=it;i++){
		memset(vis2,0,sizeof(vis2));
		
		set<int> s1,s2;
		for(j=1;j<i;j++){
			if(a[j]<=n)s1.insert(a[j]);
			else s2.insert(a[j]);
			vis2[a[j]]=1;
		}
		
		for(j=i;j<it+i;j++){
			if(j-i){
				if(a[j-i]<=n)s1.erase(a[j-i]);
				else s2.erase(a[j-i]);
			}
			vis2[a[j-i]]=0;
			
			if(a[j]<=n)s1.insert(a[j]);
			else s2.insert(a[j]);
			vis2[a[j]]=1;
			
			int mn1,mn2,mx1,mx2,mn3,mn4,mx3,mx4;
			mn1=0;mx1=n+1;
			mn2=n;mx2=n+n+1;
			
			mn3=*s1.begin();mx3=*--s1.end();
			mn4=*s2.begin();mx4=*--s2.end();
			
			for(auto k:v[a[j-i+1]]){
				if(vis2[k])continue;
				if(k<=n){
					if(k>=mn3&&k<=mx3)goto aaa;
					if(k<mn3)mn1=max(mn1,k);
					else mx1=min(mx1,k);
				}
				else{
					if(k>=mn4&&k<=mx4)goto aaa;
					if(k<mn4)mn2=max(mn2,k);
					else mx2=min(mx2,k);
				}
			}
			for(auto k:v[a[j]]){
				if(vis2[k])continue;
				if(k<=n){
					if(k>=mn3&&k<=mx3)goto aaa;
					if(k<mn3)mn1=max(mn1,k);
					else mx1=min(mx1,k);
				}
				else{
					if(k>=mn4&&k<=mx4)goto aaa;
					if(k<mn4)mn2=max(mn2,k);
					else mx2=min(mx2,k);
				}
			}
			
			res+=1ll*(i/2)*(mn3-mn1)*(mx1-mx3)*(mn4-mn2)*(mx2-mx4);
			
			aaa:;
			if(i==it)break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n+n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	for(i=1;i<=n+n;i++){
		if(vis[i])continue;
		it=0;
		dfs(i);
		chk();
	}
	cout<<res;
}