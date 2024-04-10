#include<stdio.h>
int n,i,a[100005],sb[100005],b=0,j,c=0,d=0;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if((a[i]>i-1)&(a[i]>n-i)){sb[i]=2;b++;}
	}
	while(b<n)
	{
		for(i=1;i<=n;i++)
		{
			c=d=0;
			if(sb[i]==1|sb[i]==2){continue;}
			for(j=i%a[i];j<=n;j+=a[i])
			{
				if((sb[j]==2)&(a[i]<a[j])){sb[i]=1;b++;c=d=0;break;}
				if((sb[j]==1)|(a[i]>=a[j])){c++;}d++;
			}
			if(c==d&c!=0){sb[i]=2;b++;}
		}
	}
	for(i=1;i<=n;i++){
		if(sb[i]==1){printf("A");}
		if(sb[i]==2){printf("B");}
	}

	return 0;
}