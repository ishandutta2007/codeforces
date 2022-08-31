    #include <cstdio>  
    #include <cstdlib>  
    bool find(int x){  
        if(x == 0) return 0;  
        return (x % 10 == 8) || find(x/10);  
    }  
    int main(){  
        int t,u = 0;  
        scanf("%d",&t);  
        do {  
            t++;  
            u++;  
        }while(!find(abs(t)));  
        printf("%d",u);  
    }