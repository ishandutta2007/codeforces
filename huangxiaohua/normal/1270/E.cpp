#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m;
int x[1050],y[1050];
vector<int> v;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	aaa:
	v.clear();
	for(i=1;i<=n;i++){
		if((x[i]&1)+(y[i]&1)!=1){v.push_back(i);}
	}
	m=v.size();
	if(m&&m<n){
		printf("%d\n",m);
		for(auto i:v){printf("%d ",i);}
		return 0;
	}
	v.clear();
	for(i=1;i<=n;i++){
		if(x[i]&1){v.push_back(i);}
	}
	m=v.size();
	if(!m||m==n){
		for(i=1;i<=n;i++){
			x[i]>>=1;
			y[i]>>=1;
		}
		goto aaa;
	}
	printf("%d\n",m);
	for(auto i:v){printf("%d ",i);}
}