#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;



int main()
{
    int xp,yp,xv,yv;
    scanf("%d%d%d%d",&xp,&yp,&xv,&yv);
    while(1){
        if(xp==0 && yp==0 || xp<=xv && yp<=yv){
            printf("Polycarp\n");
            return 0;
        }
        if(xv==0 && yv==0 || xp>=xv && yp>=yv){
            printf("Vasiliy\n");
            return 0;
        }
        if(yv>=xv && xp>=1)xp--;
        else yp--;
        if(xv-1==xp && yv-1==yp){
            printf("Polycarp\n");
            return 0;
        }
        if(xv>=1 && yv>=1){
            xv--,yv--;
        }else if(xv>=1)xv--;
        else yv--;
    }
    return 0;
}