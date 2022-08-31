    #include <cstdio>  
    #define max(a,b) (a>b?a:b)  
    int main(){  
        int k,a,b,v;  
        scanf("%d %d %d %d",&k,&a,&b,&v);  
        a=(a+v-1)/v;  
        // 3  .  3 = 1  
        //3  .  2 = 1.  
        // 3  .  1 = 2  
          
        // 3  .  
        // a= . k=   . b=   
        int res=0;  
        while (k<=b && a>k) {  
            a-=k;  
            b-=k-1;  
            res++;  
        }  
        printf("%d",res+max(1,a-b));  
    }