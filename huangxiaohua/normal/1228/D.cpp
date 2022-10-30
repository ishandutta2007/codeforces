#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define chk(a,b) \
	if(!a){\
		for(j=1;j<=n;j++){\
			if(used2[j]||used[j]){continue;}\
			used[j]=1;a+=v[j].size();b.push_back(j);\
		}continue;\
	}
int t,n,i,j,k,r1n,r2n,r3n,res[300500],x,y,m;
bool used[300500],used2[300500];
vector<int> r1,r2,r3,v[300500];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(used[i]){continue;}
		memset(used2,0,sizeof(used2));
		for(j=0;j<v[i].size();j++){
			used2[v[i][j]]=1;
		}
		chk(r1n,r1);chk(r2n,r2);chk(r3n,r3);
		puts("-1");return 0;
	}
	//for(i=0;i<r1.size();i++){printf("%d ",r1[i]);}puts("");for(i=0;i<r2.size();i++){printf("%d ",r2[i]);}puts("");for(i=0;i<r3.size();i++){printf("%d ",r3[i]);}puts("");
	//printf("%d %d %d\n",r1n,r2n,r3n);
	if(!r3n||r1n!=(r1.size()*(r2.size()+r3.size()))||r2n!=(r2.size()*(r1.size()+r3.size()))||r3n!=(r3.size()*(r2.size()+r1.size()))){
		puts("-1");return 0;
	}
	for(i=0;i<r1.size();i++){
		res[r1[i]]=1;
	}
	for(i=0;i<r2.size();i++){
		res[r2[i]]=2;
	}
	for(i=0;i<r3.size();i++){
		res[r3[i]]=3;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j++){
			if(res[i]==res[v[i][j]]){puts("-1");return 0;}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}