#include<bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
int main()
{
	int a,b,c,d,T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x=a+b,y=b+c,z=a+d;
		if(x&1){
			if(!y)printf("Ya Tidak Tidak Tidak\n");
			if(!z)printf("Tidak Ya Tidak Tidak\n");
			if(z&&y)printf("Ya Ya Tidak Tidak\n");
		}
		else{
			if(!y)printf("Tidak Tidak Tidak Ya\n");
			if(!z)printf("Tidak Tidak Ya Tidak\n");
			if(z&&y)printf("Tidak Tidak Ya Ya\n");
		}
	}
	return 0; 
}