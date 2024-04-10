
#include <bits/stdc++.h>
using namespace std;
 
int n,t,i,j,tmp,tmp2,tmp3,tmp4,tmp5,tmp6,res,b[200500],qn,c,d,k;
 
struct aa{
	int a;
	int b;
}a[200500],q[200500];
 
struct cmp{bool operator()(aa c,aa d){if(k==0){if(c.a!=d.a){return c.a<d.a;}return c.b<d.b;}return c.b<d.b;}};
/*int cmp(aa c,aa d){
	if(c.a!=d.a){return c.a<d.a;
	}
	return c.b<d.b;
}*/
 
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d",&n);tmp=res=tmp2=tmp3=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			a[i].b=i;
		}k=0;
		sort(a+1,a+n+1,cmp());
		
		/*for(i=1;i<=n;i++){
			printf("%2d ",a[i].a);
		}puts("");
		for(i=1;i<=n;i++){
			printf("%2d ",a[i].b);
		}puts("");*/
		
		for(i=1;i<=n;i++){
			tmp4=-1;
			tmp2=a[i].a;
			tmp3=tmp6=-1;
			for(j=i;j<=n;j++){
				if(a[j].a==tmp2){tmp++;}
				else{tmp3=a[j].b;tmp6=a[j].a;break;}
			}res=max(tmp,res);tmp=0;tmp5=1145141919;
			if(a[i].b>tmp3){b[i]=1;}
			if(b[i]==0){
				for(j=i;j<=n;j++){//printf("%d %d %d %d %d\n",a[j].a,a[j].b,tmp4,tmp,tmp5);
					if(a[j].a==tmp2&&a[j].b>tmp3){continue;}
					if(a[j].a>tmp5){break;}
					if(a[j].b<tmp4&&tmp5==1145141919){tmp5=a[j].a;continue;}
					if(a[j].b<tmp4){continue;}
					tmp++;tmp4=a[j].b;
				}
				res=max(tmp,res);tmp=0;
			}
			qn=c=d=0;
			//printf("%d %d\n",i,tmp6);

			for(j=i;j<=n&&a[j].a<=tmp6;j++){
				qn++;q[qn].a=a[j].a;q[qn].b=a[j].b;
				if(a[j].a==tmp6){d++;}
			}k=1;
			sort(q+1,q+qn+1,cmp());
			
			/*for(j=1;j<=qn;j++){
				printf("%2d ",q[j].a);
			}puts("");
			for(j=1;j<=qn;j++){
				printf("%2d ",q[j].b);
			}puts("");*/
				
			for(j=1;j<=qn;j++){
				if(q[j].a!=tmp6){c++;}else{d--;}
				res=max(res,c+d);
			}
			
			/*for(j=1;j<=n;j++){
				printf("%2d ",a[j].a);
			}puts("");
			for(j=1;j<=n;j++){
				printf("%2d ",a[j].b);
			}puts("");
			for(j=1;j<=n;j++){
				printf("%2d ",b[j]);
			}puts("");puts("");*/
		}
		printf("%d\n",n-res);
	}
}