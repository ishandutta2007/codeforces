#include<cstdio>
#include<algorithm>

int a[4];

int main()
{
    int seg,tri;
    int i;
    for(i=0;i<4;i++)scanf("%d",&a[i]);
    std::sort(a,a+4);
	seg=tri=0;
    if(a[0]+a[1]>a[2])tri=1;
    if(a[0]+a[1]==a[2])seg=1;
    if(a[1]+a[2]>a[3])tri=1;
    if(a[1]+a[2]==a[3])seg=1;
    puts(tri?"TRIANGLE":seg?"SEGMENT":"IMPOSSIBLE");
	return 0;
}