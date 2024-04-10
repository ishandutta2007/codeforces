#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,k,t,a[100500],used[100500],vn;
vector<int> v[100500];
stack<int> q1,q2;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(a[n]>1){puts("-1");return 0;}
	j=n;
	for(i=n;i>=1;i--){
		if(a[i]==1){v[i].push_back(j);j--;q1.push(i);}
		if(a[i]==2){
			if(q1.empty()){puts("-1");return 0;}
			k=q1.top();q1.pop();
			v[i].push_back(v[k][0]);used[k]=1;
		}
	}
	while(!q1.empty()){q1.pop();}
	for(i=n;i>=1;i--){
		if(a[i]==2){q2.push(i);}
		if(a[i]==1&&!used[i]){q1.push(i);}
		if(a[i]==3){
			if(q2.empty()&&q1.empty()){puts("-1");return 0;}
			if(!q2.empty()){
				k=q2.top();q2.pop();
				v[i].push_back(j);v[k].push_back(j);j--;q1.push(i);continue;
			}
			if(!q1.empty()){
				k=q1.top();q1.pop();
				v[i].push_back(j);v[k].push_back(j);j--;q1.push(i);continue;
			}
		}
	}
	for(i=1;i<=n;i++){vn+=v[i].size();}
	printf("%d\n",vn);
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j++){
			printf("%d %d\n",v[i][j],i);
		}
	}
}