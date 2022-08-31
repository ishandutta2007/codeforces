    #include <cstdio>  
      
    int n;  
    char str[10];  
    char obj[10][10] =  
    { "vaporeon", "espeon", "flareon", "jolteon", "umbreon", "leafeon", "glaceon", "sylveon" };  
      
    int main(){  
        scanf("%d %s",&n,str);  
        if(n == 8){  
            puts(obj[0]);  
        }  
        else if(n == 6){  
            puts(obj[1]);  
        }  
        else{  
            for (int i=2; i<8; i++) {  
                int is_diff = 0;  
                for (int k=0; k<7; k++) {  
                    if(str[k] == '.') continue;  
                    if(str[k] != obj[i][k]) is_diff = 1;  
                }  
                if(!is_diff){  
                    puts(obj[i]);  
                    return 0;  
                }  
            }  
            puts("flareon");  
        }  
    }