#include<bits/stdc++.h>
using namespace std;
const int dx[]={-2,-1,0,0,1,2},dy[]={0,-1,-2,2,1,0};
int n,i,j,x,y,a[55][55],qx[2505],qy[2505],he,ta;
int ask(int l1,int r1,int l2,int r2)
{
	if(l1>l2||r1>r2)
	{
		swap(l1,l2);
		swap(r1,r2);
	}
	cout<<"? "<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
	fflush(stdout);
	int s;
	cin>>s;
	return !s;
}
void work(int sx,int sy)
{
	he=ta=0;
	qx[ta]=sx;
	qy[ta]=sy;
	ta++;
	int i,j,k;
	while(he!=ta)
	{
		i=qx[he];
		j=qy[he++];
		for(k=0;k<6;k++)if(i+dx[k]>0&&j+dy[k]>0&&i+dx[k]<=n&&j+dy[k]<=n&&!~a[i+dx[k]][j+dy[k]])
		{
			a[qx[ta]=i+dx[k]][qy[ta]=j+dy[k]]=a[i][j]^ask(i,j,i+dx[k],j+dy[k]);
			ta++;
		}
	}
}
void rev()
{
	int i,j;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i+j&1)a[i][j]=!a[i][j];
}
int main()
{
	cin>>n;
	memset(a,-1,sizeof(a));
	a[1][1]=1;
	a[n][n]=0;
	work(1,1);
	a[1][2]=1;
	work(1,2);
	for(i=1;i<=n;i+=2)if(a[i][i]==1&&a[i+2][i+2]==0)break;
	if(!ask(i,i,i+1,i+2))
	{
		if(!a[i+1][i+2])rev();
	}
	else if(a[i][i+1]^a[i][i+2]^a[i+1][i]^a[i+1][i+1])
	{
		if(a[i+1][i+2])rev();
	}
	else if(!ask(i+1,i,i+2,i+2))
	{
		if(a[i+1][i])rev();
	}
	else if(a[i+1][i+1]^a[i+1][i+2]^a[i+2][i]^a[i+2][i+1])
	{
		if(!a[i+1][i])rev();
	}
	else
	{
		x=a[i+1][i]^a[i][i+1];
		y=a[i][i+1]^a[i+1][i+2];
		if((x^y)==1&&!a[i+1][i+1])
		{
			if(!a[i+1][i])rev();
		}
		else if((x^y)==1&&a[i+1][i+1])
		{
			if(a[i+1][i+2])rev();
		}
		else if((x^y)==0&&!a[i+1][i+1])
		{
			if(!a[i+1][i+2])rev();
		}
		else
		{
			if(a[i+1][i])rev();
		}
	}
	cout<<'!'<<endl;
	for(i=1;i<=n;i++,cout<<endl)for(j=1;j<=n;j++)cout<<a[i][j];
	return 0;
}