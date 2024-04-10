#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,sb[100500],md,n;

void get(int k){
	if(k==0||k>n){return;}
	printf("? %d\n",k);fflush(stdout);scanf("%d",&sb[k]);
}

bool chk(int k){return (sb[k]<sb[k-1]&&sb[k]<sb[k+1]);}

void ask(int l,int r){
	if(l>r){return;}
	md=(l+r)>>1;
	get(md-1);get(md);
	if(chk(md)){printf("! %d\n",md);exit(0);}
	if(chk(md-1)){printf("! %d\n",md-1);exit(0);}
	if(sb[md-1]<sb[md]){r=md-1;}
	else{l=md+1;}
	ask(l,r);
}

int main(){
	scanf("%d",&n);
	sb[0]=sb[n+1]=1145141919;
	ask(1,n);
}