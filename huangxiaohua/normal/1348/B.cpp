#include<stdio.h>
static int sb[1005],a[1005],n,k,t,i,j,min,max,m,tmp,mm,shit;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		min=1000;max=0;mm=0;m=0;
		scanf("%d%d",&k,&t);
		for(m=1;m<=1000;m++){sb[m]=0;a[m]=0;
			}
		
		for(j=1;j<=k;j++)
		{
			scanf("%d",&tmp);
			if(tmp>max){max=tmp;}
			if(tmp<min){min=tmp;}
			sb[tmp]=tmp;
		}
		
			for(m=1;m<=1000;m++){
				if(sb[m]!=0){mm++;a[mm]=m;
				}

			}
if(mm>t){printf("-1\n");continue;}
			m=1;
			while(mm!=t){
				if(sb[m]==0){sb[m]=m;mm++;a[mm]=m;
				}
				m++;
			}
			printf("%d\n",t*100);
			for(shit=1;shit<=100;shit++){
				for(m=1;m<=t;m++){
					printf("%d ",a[m]);
				}
			}
			printf("\n");
	}
}