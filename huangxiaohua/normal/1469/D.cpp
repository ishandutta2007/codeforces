#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,sb[200500],tmp,tmp1,nmsl;
bool used[200500];
vector<int> v,x,y;
int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);nmsl=0;
		x.clear();
		y.clear();
		v.clear();
		memset(used,0,sizeof(bool)*(n+10));
		tmp1=n;
		while(tmp1>2){
			if(tmp1==3){
				tmp=2;
			}
			else{
				tmp=sqrt(tmp1);
			}
			v.push_back(tmp);
			//printf("%d %d\n",tmp1,tmp);
			used[tmp]=1;
			tmp1=ceil(1.0*tmp1/tmp);
			if(tmp1==3&&tmp==2){
				nmsl=1;break;
			}
			if(tmp1==4&&tmp==2){
				nmsl=1;break;
			}
		}
		for(i=2;i<=n-1;i++){
			if(used[i]){continue;}
			x.push_back(i);
			y.push_back(n);
		}
		for(i=0;i<v.size();i++){
			x.push_back(n);y.push_back(v[i]);
			if(nmsl&&(i==(v.size()-1))){
				x.push_back(n);y.push_back(v[i]);
			}
			x.push_back(v[i]);y.push_back(n);
		}
		printf("%d\n",x.size());
		for(i=0;i<x.size();i++){
			printf("%d %d\n",x[i],y[i]);
		}
	}
}