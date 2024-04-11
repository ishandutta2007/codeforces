    #import<cstdio>  
    int c,b,n,t;  
      
    int main(){  
        for(scanf("%d",&n);c>=0&&n--;){  
            scanf("%d",&t);  
            if(t>50){  
                if(b==0)c-=3;  
                else b--,c--;  
            }  
            else if(t<50) c++;  
            else b++,c--;  
        }  
        puts(c<0?"NO":"YES");  
    }