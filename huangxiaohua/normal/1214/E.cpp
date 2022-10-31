#include<stdio.h>

static int a[100001][2],n,i,b[200001],mai[200001],m=0;

int paixu(int shuzu[][2],int daxiao)
{
	long long int i,j,k,l;
	l=daxiao;
	if(l>=1000){l=1000;}
	for(l=l;l>=1;l/=2)
	{
		for(i=l;i<=daxiao;i++)
		{
			for(j=i;((shuzu[j][1]>shuzu[j-l][1])&(j>l));j-=l)
			{
				k=shuzu[j][1];shuzu[j][1]=shuzu[j-l][1];shuzu[j-l][1]=k;
				k=shuzu[j][0];shuzu[j][0]=shuzu[j-l][0];shuzu[j-l][0]=k;
			}
		}
	}
	for(i=2;i<=daxiao;i++)
	{
		if((shuzu[i-1][1]==shuzu[i][1])&(shuzu[i-1][0]>shuzu[i][0])){
		k=shuzu[i][0];shuzu[i][0]=shuzu[i-1][0];shuzu[i-1][0]=k;
		}
	}
	return 0;
}

int aaa(){
	for(i=1;i<=n;i++)
	{
		b[a[i][0]]=i;
		mai[i]=a[i][0];m++;
	}
	return 0;
}

int bbb(){
	for(i=1;i<=n;i++)
	{
		b[a[i][0]+1]=a[i][1]+b[a[i][0]];
		if(mai[b[a[i][0]+1]]<=0){mai[b[a[i][0]+1]]=a[i][0]+1;m++;}
		else{b[a[i][0]+1]--;
		}
	}
	return 0;
}

int ccc(){
	for(i=1;i<=m-1;i++)
	{
		printf("%d %d\n",mai[i],mai[i+1]);
	}
	return 0;
}

int ddd(){
	for(i=1;i<=2*n;i++)
	{
		if(mai[b[i]]!=i){printf("%d %d\n",mai[b[i]],i);}
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i][0]=i*2-1;
		scanf("%d",&a[i][1]);
	}
	paixu(a,n);
	aaa();
	bbb();
	ccc();
	ddd();
	return 0;
}