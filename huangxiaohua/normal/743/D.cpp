#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> v[200500];
queue<int> q;
int n,i,j,x,y;
ll a[200500],son1[200500],son2[200500],sum[200500],son[200500],res=-114514191981089336ll;
bool used[200500];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		son1[i]=son2[i]=-1145141919810893364ll;
	}
	for(i=1;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		son[x]++;son[y]++;
		v[y].push_back(x);v[x].push_back(y);
	}
	for(i=2;i<=n;i++){
		if(son[i]==1){q.push(i);}
	}
	while(!q.empty()){
		x=q.front();q.pop();
		sum[x]+=a[x];used[x]=1;
		for(i=0;i<v[x].size();i++){
			if(used[v[x][i]]){continue;}
			son[v[x][i]]--;
			if(v[x][i]-1&&(son[v[x][i]]==1)){q.push(v[x][i]);}
			sum[v[x][i]]+=sum[x];
			
			if(max(sum[x],son1[x])>son1[v[x][i]]){son2[v[x][i]]=son1[v[x][i]];son1[v[x][i]]=max(sum[x],son1[x]);}
			else{
				if(max(sum[x],son1[x])>son2[v[x][i]]){son2[v[x][i]]=max(sum[x],son1[x]);}
			}
			res=max(res,son1[x]+son2[x]);
		}
		//printf("%lld %lld %lld\n",x,sum[x],son1[x]);
	}
	res=max(son1[1]+son2[1],res);
	if(res<-1e15){puts("Impossible");return 0;
	}
	printf("%lld",res);
}