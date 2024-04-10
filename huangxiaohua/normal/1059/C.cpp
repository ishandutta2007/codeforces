#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int i,j,k,n,m,t,res=1;

void get(int x,int y){
	if(!x){return;}
	if(x==3){
		printf("%d %d %d",y,y,y*3);return;
	}
	
	int z=x/2;
	while(1){
		printf("%d ",y);
		x--;
		if(x==z){break;}
	}
	get(z,y*2);
}

int main(){
	scanf("%d",&n);
	get(n,1);
}