#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,tmp,tmp1,tmp2;
ll m,p[666]={1},tmp3;
queue<int> res;
bool chk(){
	int i;tmp=1;
	if(n>=62){for(i=1;i<=n-62;i++){res.push(i);}tmp=n-61;}
	else{if(m+1>p[n-1]){return 0;}}
	while(tmp<=n){
		tmp2=tmp;
		while(m-p[n-tmp2-1]>=0){
			m-=p[n-tmp2-1];tmp2++;
			if(tmp2>n){tmp2--;break;}
		}
		for(i=tmp2;i>=tmp;i--){res.push(i);}
		tmp=tmp2+1;
	}
	return 1;
}

int main(){
	for(i=1;i<=62;i++){p[i]=p[i-1]*2;}
	scanf("%d",&t);
	while(t--){
		queue<int> clr;swap(clr,res);
		scanf("%d%lld",&n,&m);m--;
		if(chk()){while(!res.empty()){printf("%d ",res.front());res.pop();}puts("");}
		else{puts("-1");}
	}
}