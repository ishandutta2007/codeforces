#include<bits/stdc++.h>
using namespace std;
int n,i,j,x[60],y[60],xx,yy,a,b,tmp;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		for(i=1;i<=50;i++){
			x[i]=y[i]=0;
		}xx=a;yy=b;
		for(i=1;i<=a;i++){
			for(j=1;j<=b;j++){
				scanf("%d",&tmp);
				if(tmp==1){
					if(x[i]==0){x[i]=1;xx--;}
					if(y[j]==0){y[j]=1;yy--;}
				}
			}
		}
		tmp=min(xx,yy);
		if(tmp%2==1){puts("Ashish");
		}else{puts("Vivek");
		}
	}
}