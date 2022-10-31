#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j;
ll nmsl,vis[1005000];
__int128 k,l,r,t,x,y,t0,sb,t1;
ll rd(){cin>>nmsl;return nmsl;}

int main(){
	k=rd();l=rd();r=rd();t=rd();x=rd();y=rd();
	k-=l;r-=l;
	if(y<=x){
		if(k+y<=r){k+=y;}
		k-=t*x;
		k+=(t-1)*y;
		puts(k<0?"No":"Yes");return 0;
	}
	if(y+x<=r){puts("Yes");return 0;}
	if(k+y<=r){k+=y;}
	while(1){
		t0=k/x;
		t-=t0;k-=t0*x;
		if(vis[k]||t<=0){puts("Yes");return 0;}
		vis[k]=1;k+=y;
		if(k>r){puts("No");return 0;}
	}
}