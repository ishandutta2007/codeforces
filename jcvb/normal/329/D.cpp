#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int n;
int main()
{
    scanf("%d",&n);
    if(n==5){
        printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
    }else if(n==3){
        printf(">vv\n^<.\n^.<\n1 3\n");
    }else{
        for (int i=1;i<=33;i++)putchar('>');
        for (int i=1;i<=33;i++)printf(".>");
        printf("v\n");
        
        for (int i=3;i<=99;i+=2){
            printf("^v");
            for (int i=1;i<=33;i++)printf("<.");
            for (int i=1;i<=32;i++)printf("<");
            printf("\n");
            printf("^>");
            for (int i=1;i<=33;i++)printf(">");
            for (int i=1;i<=32;i++)printf(".>");
            printf("v\n");
        }
        printf("^<");
            for (int i=1;i<=32;i++)printf("<.");
            for (int i=1;i<=33;i++)printf("<");
            printf("<\n");
        
        printf("1 1\n");
    }
    return 0;
}