#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,it,a[1005000],fa[10005000];
bool op[10050000];
struct SB{
	int id,x,y;
	bool operator<(const SB a)const{return (x==a.x)?y<a.y:x<a.x;}
};
vector<SB>v1,v2;
void add(int x,int y,int z,int b){
	fa[++it]=x;op[it]=b;
	v2.push_back({it,y,z});
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;it=0;
		for(i=1;i<=n;i++)cin>>a[i];
		v1.push_back({0,-11451419,-11451419});
		for(i=1;i<=n;i++){
			v2.clear();
			for(auto &[id,x,y]:v1){
				if(x<-a[i])add(id,-a[i],y,1);
				else if(y<-a[i])add(id,x,-a[i],1);
				if(x<a[i])add(id,a[i],y,0);
				else if(y<a[i])add(id,x,a[i],0);
			}
			if(v2.empty()){cout<<"NO\n";goto ccc;}
			v1.clear();k=1e9;
			sort(v2.begin(),v2.end());
			for(auto &i:v2)if(i.y<k){k=i.y;v1.push_back(i);}
		}
		i=(*v1.begin()).id;j=n;
		while(i){
			if(op[i])a[j]*=-1;
			j--;i=fa[i];
		}
		cout<<"YES\n";
		for(i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<'\n';
		ccc:;
	}
}