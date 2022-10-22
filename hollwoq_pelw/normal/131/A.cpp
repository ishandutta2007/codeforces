#include<stdio.h>
#include<string.h>
int main() { 
    int i,k=0; 
    char str[100]; 
    scanf("%s",str); 
    for(i=1; i<strlen(str); i++) { 
        if(str[i]>=65&&str[i]<=90) k++; 
    } 
    if(k==strlen(str)-1) { 
        for(i=0; i<strlen(str); i++) { 
            if(str[i]>=65&&str[i]<=90) str[i]=97+str[i]-65; 
            else if(str[i]>=97&&str[i]<=122) str[i]=65+str[i]-97; 
        } 
    }
    printf("%s\n",str);
    return 0;
}