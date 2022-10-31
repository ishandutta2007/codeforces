#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l[5050],r[5050],a[5050],res,sum,num[5050];
vector<int> v[5050];

int chk(int x){
	int res=sum,i,j,tmp=6666;
	memset(num,0,sizeof(num));
	for(i=l[x];i<=r[x];i++){
		if(a[i]==1){res--;}
		a[i]--;
	}
	for(i=1;i<=n;i++){
		if(a[i]==1){
			for(auto j:v[i]){
				num[j]++;
			}
		}
	}
	for(i=1;i<=m;i++){
		if(i==x){continue;}
		tmp=min(tmp,num[i]);
	}
	for(i=l[x];i<=r[x];i++){
		a[i]++;
	}
	return res-tmp;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&l[i],&r[i]);
		for(j=l[i];j<=r[i];j++){
			v[j].push_back(i);
			if(!a[j]){sum++;}
			a[j]++;
		}
	}
	for(i=1;i<=m;i++){
		res=max(res,chk(i));
	}
	cout<<res;
}