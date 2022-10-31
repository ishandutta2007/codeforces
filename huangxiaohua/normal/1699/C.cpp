#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t,f[100500],l,r;
vector<pair<int,int> >v;
ll res=1;

void add(int x,int y){
	for(;x<=n;x+=(-x&x)){f[x]+=y;}
}
int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;v.clear();
		l=n+1;r=-1;
		for(i=1;i<=n;i++){
			cin>>k;
			v.push_back({k,i});
			f[i]=0;
		}
		for(i=1;i<=n;i++)add(i,1);
		res=1;
		sort(v.begin(),v.end());
		for(auto [x,y]:v){
			//printf("NMSL%d %d %d %d %d\n",x,y,l,r,res);
			if(l<=y&&y<=r){
				res=res*(get(r)-get(l-1))%M;
			}
			add(y,-1);
			l=min(l,y);r=max(r,y);
		}
		cout<<res<<'\n';
	}
}