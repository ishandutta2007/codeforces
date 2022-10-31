#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,m,a,b,sb[200500],t1,t2,res;
priority_queue<int> q;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		res=0;
		while(!q.empty()){q.pop();}
		
		if(a>b){t1=a-b-1;t2=n-b;}
		else{t1=b-a-1;t2=b-1;}
		for(i=1;i<=m;i++){
			scanf("%d",&sb[i]);
			q.push(sb[i]);
		}
		for(i=1;i<=min(t1,m);i++){
			while(!q.empty()){
				if(i+q.top()<=t2){res++;q.pop();break;}
				q.pop();
			}
		}
		printf("%d\n",res);
	}
}