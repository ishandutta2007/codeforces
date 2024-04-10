#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,it,res,f[60050];
vector<int> v[30050];
struct sb{
	int x,y,z;
	bool operator<(const sb a)const{return z<a.z;}
}s[105];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&j,&k);
		if(k>=0){v[j].push_back(k);}
		else{s[++it].x=j;s[it].y=-k;s[it].z=j+k;}
	}
	for(i=1;i<=30000;i++){
		if(m<i){break;}
		for(auto j:v[i]){res++;m+=j;}
	}
	n=it;sort(s+1,s+n+1);
	for(i=1;i<=n;i++){
		k=s[i].y;
		for(j=m;j>=max(k,s[i].x);j--){
			f[j]=max(f[j],f[j-k]+1);
		}
	}
	printf("%d",f[m]+res);
}