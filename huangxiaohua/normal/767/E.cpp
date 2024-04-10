#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,cur,a[100500],b[100500],r1[100500],vis[100500];
ll sum,res;
priority_queue<pair<int,int> > q;

int main(){
	scanf("%d%d",&n,&cur);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r1[i]=a[i]/100;a[i]%=100;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]*=(100-a[i]);
	}
	for(i=1;i<=n;i++){
		j=a[i];k=b[i];
		if(!(j%100)){vis[i]=1;continue;}
		sum+=k;
		if(cur>=j){
			cur-=j;q.push({-k,i});res+=k;continue;
		}
		else{
			cur+=100-j;
			if(!q.empty()&&q.top().first+k>0){
				res+=q.top().first+k;q.pop();q.push({-k,i});
			}
		}
	}
	while(!q.empty()){
		auto [i,j]=q.top();q.pop();vis[j]=1;
	}
	printf("%lld\n",sum-res);
	for(i=1;i<=n;i++){
		if(vis[i]){
			printf("%d %d\n",r1[i],a[i]);
		}
		else{
			printf("%d 0\n",r1[i]+1);
		}
	}
}