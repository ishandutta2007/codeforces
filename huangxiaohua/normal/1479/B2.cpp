#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,sb[100500],md,n,l,r,res,x,y;
vector<int> v[100500];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
		v[sb[i]].push_back(i);
	}
	for(i=0;i<=n;i++){
		v[i].push_back(114514);
	}
	for(i=1;i<=n;i++){
		if(l==sb[i]||r==sb[i]){continue;}
		if(l!=sb[i]&&r!=sb[i]){
			x=*lower_bound(v[l].begin(),v[l].end(),i);
			y=*lower_bound(v[r].begin(),v[r].end(),i);
			if(x>y){res++;l=sb[i];}
			else{res++;r=sb[i];}
		}
	}
	printf("%d",res);
}