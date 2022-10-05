#include<stdio.h>
#include<algorithm>

using namespace std;

int a,b,c,d,e,f;
char ans[4]="ABC";

int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(a<b)swap(a,b);
    if(c<d)swap(c,d);
    if(e<f)swap(e,f);
    if(a*b+c*d+e*f==a*a){
    }
    else if(a*b+c*d+e*f==c*c){
        swap(a,c);
        swap(b,d);
        swap(ans[0],ans[1]);
    }
    else if(a*b+c*d+e*f==e*e){
        swap(a,e);
        swap(b,f);
        swap(ans[0],ans[2]);
    }
    else{puts("-1");return 0;}
    if(a==c && a==e){
        printf("%d\n",a);
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++)putchar(ans[0]);
            puts("");
        }
        for(int i=0;i<d;i++){
            for(int j=0;j<a;j++)putchar(ans[1]);
            puts("");
        }
        for(int i=0;i<f;i++){
            for(int j=0;j<a;j++)putchar(ans[2]);
            puts("");
        }
        return 0;
    }
    int flag=0;
    if(c==a-b && e==a-b)flag=1;
    if(c==a-b && f==a-b)swap(e,f),flag=1;
    if(d==a-b && e==a-b)swap(c,d),flag=1;
    if(d==a-b && f==a-b)swap(c,d),swap(e,f),flag=1;
    if(flag){
        printf("%d\n",a);
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++)putchar(ans[0]);
            puts("");
        }
        for(int i=0;i<a-b;i++){
            for(int j=0;j<d;j++)putchar(ans[1]);
            for(int j=0;j<f;j++)putchar(ans[2]);
            puts("");
        }
        return 0;
    }
    puts("-1");
}