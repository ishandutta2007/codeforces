#include<stdio.h>
int a,b,c,d,e,f;
void swap(int &a,int &b){int t=a;a=b;b=t;}
bool fit(int a,int b,int c,int d)
{
    if(a<=c&&b<=d)return true;
    return false;
}
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(fit(c,d,a,b)&&(fit(e,f,a-c,b)||fit(e,f,a,b-d)||fit(f,e,a-c,b)||fit(f,e,a,b-d)))puts("YES");
    else if(fit(d,c,a,b)&&(fit(e,f,a-d,b)||fit(e,f,a,b-c)||fit(f,e,a-d,b)||fit(f,e,a,b-c)))puts("YES");
    else if(fit(c,d,b,a)&&(fit(e,f,b-d,a)||fit(e,f,b,a-c)||fit(f,e,b-d,a)||fit(f,e,b,a-c)))puts("YES");
    else if(fit(d,c,b,a)&&(fit(e,f,b-d,a)||fit(e,f,b,a-c)||fit(f,e,b-d,a)||fit(f,e,b,a-c)))puts("YES");
    else puts("NO");
}