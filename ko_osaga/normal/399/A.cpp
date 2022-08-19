    #include <cstdio>  
    int main(){  
        int M,N,c,n;  
        int printRight=0;  
        scanf("%d %d %d",&M,&c,&n);  
        N=c>n+1?c-n:1;  
        if(c+n<M){  
            printRight=1;  
            M=c+n;  
        }  
        if(N!=1) printf("<< ");  
        for (int i=N; i<=M; i++) {  
            if(i==c) printf("(%d) ",i);  
            else printf("%d ",i);  
        }  
        if(printRight) printf(">>");  
    }