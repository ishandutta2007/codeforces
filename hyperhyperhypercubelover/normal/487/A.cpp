#include<cstdio>
#include<algorithm>

int main()
{
    int a,b,c,d,e,f,g,h,i;
    int x,y,z,res=1e9;
    scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
    for(y=0;y<=200;y++)for(z=0;z<=200;z++)
	{
        if(y+b<=f)continue;
		if(e<=z+c)x=0;
		else x=std::max(0,(d+y+b-f-1)/(y+b-f)*(e-z-c)-a+1);
		if(x*g+y*h+z*i<res)res=x*g+y*h+z*i;
	}
	printf("%d",res);
}