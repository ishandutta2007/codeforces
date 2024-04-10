#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t;
ll res;

priority_queue<int> q;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k%2==0){res+=k;}
			else{res-=k;}
			q.push(k);
		}
		k=1;
		while(!q.empty()){
			res+=q.top()*k;
			k*=-1;
			q.pop();
		}
		//printf("%lld\n",res);
		if(!res){puts("Tie");continue;}
		if(res>0){puts("Alice");continue;}
		if(res<0){puts("Bob");continue;}
	}
}