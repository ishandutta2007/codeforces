#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,wx,wy;
char sb[5050];

bool chk(int k){
	int i,j,x=0,y=0;
	for(i=1;i<=k;i++){
		if(sb[i]=='L'){x--;}
		if(sb[i]=='R'){x++;}
		if(sb[i]=='U'){y++;}
		if(sb[i]=='D'){y--;}
	}
	wx=x;wy=y;
	
	x=y=0;
	for(i=1;i<=n;i++){
		if(sb[i]=='L'&&((x-1!=wx)||(y!=wy))){x--;}
		if(sb[i]=='R'&&((x+1!=wx)||(y!=wy))){x++;}
		if(sb[i]=='U'&&((x!=wx)||(y+1!=wy))){y++;}
		if(sb[i]=='D'&&((x!=wx)||(y-1!=wy))){y--;}
		//printf("%d %d %d\n",x,y,k);
	}
	//printf("%d %d %d %d %d\n",wx,wy,x,y,k);
	if(!x&&!y){return 1;}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>sb+1;
		n=strlen(sb+1);
		for(i=1;i<=n;i++){
			if(chk(i)){
				printf("%d %d\n",wx,wy);goto aaa;
			}
		}
		puts("0 0");
		aaa:;
	}
}