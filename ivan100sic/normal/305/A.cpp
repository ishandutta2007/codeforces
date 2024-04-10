#include <cstdio>
using namespace std;

int t1,t2,t3,t4,t5,n,i,j,k;

int main(){
    scanf("%d",&n);
    t1=t2=t3=t4=t5=-1;
    while (n--){
        scanf("%d",&j);
        if (j==0) t1=j; else
        if (j<=9) t2=j; else
        if (j<=99 && j%10==0) t3=j; else
        if (j==100) t4=j; else t5=j;
    }
    if (t1!=-1) k++;
    if (t2!=-1) k++;
    if (t3!=-1) k++;
    if (t4!=-1) k++;
    if (t2==-1 && t3==-1 && t5>-1) k++;
    printf("%d\n",k);
    if (t1!=-1) printf("%d\n",t1);
    if (t2!=-1) printf("%d\n",t2);
    if (t3!=-1) printf("%d\n",t3);
    if (t4!=-1) printf("%d\n",t4);
    if (t5!=-1 && t2==-1 && t3==-1) printf("%d\n",t5);
    return 0;
}