#include<bits/stdc++.h>
using namespace std;
 
int n,i,j,t,a[5050],b[5050],c[10050],mex,m[5050],tmp,bn;
 
int me(){
	int i;
	for(i=mex;i>=1;i--){
		if(m[i]==0){return i;
		}
	}
}
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(m,0,n*2*4+50);
		memset(c,0,n*2*4+50);
		mex=2*n;bn=0;
		for(i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
		}
		for(i=n*2;i>=1;i--){
			mex=me();
			m[a[i]]=1;tmp++;
			if(a[i]==mex){bn++;b[bn]=tmp;tmp=0;}
		}
		sort(b+1,b+bn+1);
		c[0]=1;
		for(i=1;i<=bn;i++){
			for(j=0;j<=n*2;j++){
				if(c[j]<i+1&&c[j]!=0&&c[j+b[i]]==0){c[j+b[i]]=i+1;}
			}
		}
		if(c[n]>=1){puts("YES");
		}else{puts("NO");
		}
	}
}