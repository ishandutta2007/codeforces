#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int n;
int l,x,y;
int a[100005];

int fin(int d){
    for (int i=1;i<=n;i++){
        int a1=a[i]-d;
        if(*lower_bound(a+1,a+1+n,a1)==a1)return 1;
        /*int a2=a[i]+d;
        if(*lower_bound(a+1,a+1+n,a2)==a2)return 1;
        */
    }
    return 0;
}
int main()
{
    scanf("%d%d%d%d",&n,&l,&x,&y);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=-1111111;
    int box=fin(x);
    int boy=fin(y);
    if(box && boy){
        printf("0\n");
    }else if(box || boy){
        if(box)printf("1\n%d\n",y);
        else printf("1\n%d\n",x);
    }else{
        for (int i=1;i<=n;i++){
            int a1=a[i]-x;
            if(a1>=0 && a1<=l){
                if(*lower_bound(a+1,a+1+n,a1+y)==a1+y || *lower_bound(a+1,a+1+n,a1-y)==a1-y){
                    printf("1\n%d\n",a1);
                    return 0;
                }
            }
            a1=a[i]+x;
            if(a1>=0 && a1<=l){
                if(*lower_bound(a+1,a+1+n,a1+y)==a1+y || *lower_bound(a+1,a+1+n,a1-y)==a1-y){
                    printf("1\n%d\n",a1);
                    return 0;
                }
            }
        }
        printf("2\n%d %d\n",min(x,y),max(x,y));
    }
    return 0;
}