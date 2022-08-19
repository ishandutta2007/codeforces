#import<cstdio>  
main(){int n,a[9],*p=a,j,e;for(scanf("%d",&n);e<9;e++)scanf("%d",a+e),p=*p<a[e]?p:a+e;e=n;if(n/=*p)for(;n--;){for(j=8;e%*p<a[j]-*p;j--);e-=a[j];putchar(j+49);}else puts("-1");}