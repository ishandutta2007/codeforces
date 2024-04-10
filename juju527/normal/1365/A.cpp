#include<bits/stdc++.h>
using namespace std;
bool visl[55],visc[55];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,m;
		n=read();m=read();
		int l=n,c=m;
		memset(visl,0,sizeof(visl));
		memset(visc,0,sizeof(visc));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				int x=read();
				if(x){
					if(!visl[i])l--;
					if(!visc[j])c--;
					visl[i]=visc[j]=1;
				}
			}
		if(l<c)swap(l,c);
		if(c&1)printf("Ashish\n");
		else printf("Vivek\n");
	}
	return 0;
}