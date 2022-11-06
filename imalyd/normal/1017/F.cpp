#include<bits/stdc++.h>
using namespace std;
#define ui unsigned int
ui n,a,b,c,d,ans;
bitset<50000010>b5,b1;
void cal(ui v){
	for(ui i=v<<1;i<=n;i+=v){
		if(i%6==5)b5[i/6+1]=1;
		if(i%6==1)b1[i/6+0]=1;
	}
	ui f=a*v*v*v+b*v*v+c*v+d,g=0,nn=n;
	while(nn)g+=(nn/=v);
	ans+=f*g;
}
int main(){//printf("%d",(sizeof(b5)+sizeof(b1))>>20);
	scanf("%u%u%u%u%u",&n,&a,&b,&c,&d);
	cal(2u),cal(3u);
	for(ui i=1;1;i++){
		if(!b5[i])cal(6*i-1);
		if(!b1[i])cal(6*i+1);
		if(n<6*i+1)break;
	}
	printf("%u",ans);
	return 0;
}