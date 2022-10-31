#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 ld;

int i,j,k,n,m,t,p[21][600500],it,a[300500];
ll f[300500][21],tot,NMSL[600500],cnm;

map<int,int> mp;
void fuck(int x,int y){
	int i,j,k,t;
	if(!mp[y])mp[y]=++it;
	k=mp[a[x]]; for(i=x;i<=n;i+=(-i&i))for(t=1;t<=20;t++)f[i][t]-=p[t][k];
	k=mp[y];a[x]=y; for(i=x;i<=n;i+=(-i&i))for(t=1;t<=20;t++)f[i][t]+=p[t][k];
}

bool get(int l,int r,ld w){
	int i,j,k,t;
	l--;
	if(w==1)return 1;
	ll sb;
	for(t=1;t<=20;t++){
		sb=0;
		for(i=r;i;i-=(-i&i))sb+=f[i][t];
		for(i=l;i;i-=(-i&i))sb-=f[i][t];
		if(sb%w)return 0;
	}
	return 1;
}

int main(){
	mt19937_64 rng(114514);
	m=600000;
	for(i=1;i<=m;i++){
		p[1][i]=i;
		tot+=i;
		NMSL[i]=rng();
	}
	for(i=2;i<=20;i++){
		memcpy(p[i],p[1],sizeof(p[1]));
		shuffle(p[i]+1,p[i]+m+1,rng);
	}
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>k;fuck(i,k);
	}
	while(t--){
		int op,x,y,w;
		cin>>op;
		if(op==1){
			cin>>x>>y;fuck(x,y);
		}
		else{
			cin>>x>>y>>w;
			if(get(x,y,w))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}