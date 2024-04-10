#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int maxn=103;  
int cn,x[maxn][maxn][maxn],y[maxn][maxn][maxn],area[maxn*maxn];  
int w,h,n,i,x1,y1,x2,y2;  
void dfs(int x1,int x2,int y1,int y2)  
{  
    for(int i=y1+1; i<y2; i++)  
    {  
        if(y[x1][x2][i])  
        {  
            dfs(x1,x2,i,y2);  
            dfs(x1,x2,y1,i);  
            return;  
        }  
    }  
    for(int i=x1+1; i<x2; i++)  
    {  
        if(x[y1][y2][i])  
        {  
            dfs(i,x2,y1,y2);  
            dfs(x1,i,y1,y2);  
            return;  
        }  
    }  
    area[cn++]=(x2-x1)*(y2-y1);  
}  
int main()  
{  
    while(~scanf("%d%d%d",&w,&h,&n))  
    {  
        memset(x,0,sizeof(x));  
        memset(y,0,sizeof(y));  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
            if(x1==x2)x[y1][y2][x1]=1;  
            if(y1==y2)y[x1][x2][y1]=1;  
        }  
        cn=0;  
        dfs(0,w,0,h);  
        sort(area,area+cn);  
        for(int i=0; i<cn; i++)  
        {  
            printf(i==cn-1?"%d\n":"%d ",area[i]);  
        }  
    }  
    return 0;  
}