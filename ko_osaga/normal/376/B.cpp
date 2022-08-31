    #import<cstdio>  
    int d[101],n,m,a,b,c,r;main(){scanf("%d%d",&n,&m);for(;m--;)scanf("%d%d%d",&a,&b,&c),d[a]+=c,d[b]-=c;for(;n;n--)r+=d[n]>0?d[n]:0;printf("%d",r);}