    #include <cstdio>  
      
    int main(){  
        int n,f=0,z=0,t;  
        scanf("%d",&n);  
        for (int i=0; i<n; i++) {  
            scanf("%d",&t);  
            if(t==0) z++;  
            if(t==5) f++;  
        }  
        if(z==0) printf("-1");  
        else if(f<9) printf("0");  
        else{  
            f=f/9;  
            for (int i=0; i<f*9; i++) {  
                printf("5");  
            }  
            for (int i=0; i<z; i++) {  
                printf("0");  
            }  
        }  
          
    }