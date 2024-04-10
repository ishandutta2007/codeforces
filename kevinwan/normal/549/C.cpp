#include <iostream>
using namespace std;
int o,e;
int main()
{
    int n,k,r,x,i;
    scanf("%d%d",&n,&k);
    r=n-k;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(x&1)o++;
        else e++;
    }
    if(r==0){
        if(o&1)printf("Stannis");
        else printf("Daenerys");
    }
    else if(r&1){
        bool s=1;
        if(e<=r/2&&!(k&1))s=0;
        if(o<=r/2)s=0;
        if(e<=r/2+1&&!(k&1)&&o<=r/2+1)s=0;
        if(s)printf("Stannis");
        else printf("Daenerys");
    }
    else{
        bool d=1;
        if(e<=r/2&&(k&1))d=0;
        if(d)printf("Daenerys");
        else printf("Stannis");
    }
}