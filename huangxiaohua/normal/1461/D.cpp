#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll,bool> mp;

int i,j,k,t,n,m,mx,qq;
vector<int> v;

ll sb;
void chk(vector<int> v){
	
	ll tmp=0,l,r,mid;
	vector<int> v1,v2;
	
	if(v.size()==1){mp[v[0]]=1;}
	
	for(int i=0;i<v.size();i++){
		tmp+=v[i];
	}mp[tmp]=1;
	
	sort(v.begin(),v.end());
	
	mid=(v[0]+v[v.size()-1])/2;
	
	for(int i=0;i<v.size();i++){
		if(v[i]<=mid){v1.push_back(v[i]);}
		else{v2.push_back(v[i]);}
	}
	if(!v1.size()||!v2.size()){return;}
	chk(v1),chk(v2);
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&qq);
		
		mp.clear();
		v.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			v.push_back(k);
		}
		
		chk(v);
		
		while(qq--){
			scanf("%lld",&sb);
			if(mp[sb]){puts("Yes");continue;}
			puts("No");
		}
	}
}