#include<stdio.h>

int read()
{
	int s=0, w=1; register char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}


int main()
{
	register int a[666],b[666],n,m,i,j,y,yy;
	scanf("%d",&n);
	while(n--){
		m=read();y=0;
		for(i=1;i<=m;i++){
			a[i]=read();
		}
		for(i=1;i<=m;i++){
			b[i]=read();
		}
		if(m%2==1&&a[m/2+1]!=b[m/2+1]){puts("nO");continue;}
		for(i=1;i<=m/2;i++){
			for(j=1;j<=m;j++){
				if(m%2==1&&j==m/2+1){continue;}
				if(a[i]==b[m+1-j]&&a[m+1-i]==b[j]){b[j]=b[m+1-j]=0;y+=2;yy=1;break;}
			}
			if(yy==0){break;}	
		}
		puts((y/2==m/2)?"yES":"nO");
	}
}