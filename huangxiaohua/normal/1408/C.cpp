#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t;
double t1[100500],t2[100500],rd[100500],l,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lf",&n,&l);
		for(i=1;i<=n;i++){
			scanf("%lf",&rd[i]);
		}
		n++;
		rd[0]=0;rd[n]=l;
		t1[1]=t2[n]=0;
		for(i=1;i<=n;i++){
			t1[i]=t1[i-1]+(rd[i]-rd[i-1])/i;
		}
		for(i=n-1;i>=0;i--){
			t2[i]=t2[i+1]+(rd[i+1]-rd[i])/(n-i);
		}
		for(i=0;i<=n-1;i++){
			//printf("%lf %lf\n",t1[i],t2[i]);
			if((t2[i]>(t1[i]-0.0000001))&&(t2[i+1]<(t1[i+1]+0.0000001))){
				if(t1[i]<(t2[i+1]+0.000001)){
					res=t2[i+1]+(rd[i+1]-rd[i]-(t2[i+1]-t1[i])*(i+1))/(n+1);
				}
				else{
					res=t1[i]+(rd[i+1]-rd[i]+(t2[i+1]-t1[i])*(n-i))/(n+1);
				}
			}
		}
		printf("%.10lf\n",res);
	}
}