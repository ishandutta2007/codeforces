#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m;
int a[15]={0,6,10,15,14,21,22,26,33,34,35,38};
int main(){
	int T;T=read();
	while(T--){
		n=read();
		for(i=1;i<=11;i++)
			for(j=i+1;j<=11;j++)
				for(k=j+1;k<=11;k++){
					int tmp=n-a[i]-a[j]-a[k];
					if(tmp>0 && tmp!=a[i] && tmp!=a[j] && tmp!=a[k]){
						printf("YES\n%d %d %d %d\n",a[i],a[j],a[k],tmp);
						goto END;
					}
				}
		puts("NO");
		END:
		;;;
	}
	return 0;
}