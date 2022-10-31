#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,siz[1005000],sb[1005000],num[1005000];
ll res,cur;
bitset<1000005> b;
vector<int> v[1005000],v1;

void dfs(int x){
	bool y=1;
	for(auto i:v[x]){
		dfs(i);
		if(siz[i]*2>n)y=0;
		siz[x]+=siz[i];
	}
	siz[x]++;
	if((n-siz[x])*2>n){
		y=0;
	}
	sb[x]=y;
	cur+=siz[x];
}

ll fuck(int x){
	int i,j,k;
	ll r1,r2;
	v1.clear();
	memset(num,0,sizeof(num));
	num[n-siz[x]]=1;
	for(auto i:v[x]){
		num[siz[i]]++;
	}
	for(i=1;i<=n;i++){
		if(!num[i])continue;
		//printf("a%d %d\n",i,num[i]);
		k=i;
		for(j=1;;j*=2){
			if(j<=num[i]){
				num[i]-=j;
				v1.push_back(k);
			}
			else{
				if(num[i])v1.push_back(num[i]*i);
				break;
			}
			k*=2;
		}
	}
	b.reset();b[0]=1;
	for(auto i:v1){
		//cout<<i<<endl;
		b|=(b<<i);
	}
	for(r1=n/2;;r1--){
		if(b[r1])break;
	}
	r2=n-1-r1;
	return r1*r2;
}

void dfs2(int x,ll cur){
	//printf("a%d %d\n",x,cur);
	if(sb[x]){
		res=max(res,cur+fuck(x));
	}
	for(auto i:v[x]){
		dfs2(i,cur-siz[i]+n-siz[i]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=2;i<=n;i++){
		cin>>k;
		v[k].push_back(i);
	}
	dfs(1);
	dfs2(1,cur);
	cout<<res;
}