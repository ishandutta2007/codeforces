#include <cstdio>
using namespace std;

int main()
{
    int n,m,i=1;
    scanf("%d%d",&n,&m);
    while(n+m>0){
        if((i%2==0 && i%3!=0) && n>0)
            n--;
        if((i%3==0 && i%2!=0) && m>0)
            m--;
        if(i%6==0){
            if(m*3>=n*2){
                m--;
            }else{
                n--;
            }
        }
        ++i;
    }
    printf("%d",i-1);
}