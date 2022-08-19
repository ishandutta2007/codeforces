#include <cstdio>

int cnt,ca,cb;
int ask(int a,int b){
    printf("? %d %d\n",a,b);
    fflush(stdout);
    int tem;
    scanf("%d",&tem);
    return tem;
}
int main(){
    cnt=ask(0,0);
    for(int i=29;i>=0;i--){
        if(cnt==0){
            if(ask(ca|(1<<i),cb)==-1){
                ca|=(1<<i),cb|=(1<<i);
            }
            continue;
        }
        int t1=ask(ca|(1<<i),cb|(1<<i));
        if(t1!=cnt){
            if(cnt==1)ca|=(1<<i);
            else cb|=(1<<i);
            cnt=ask(ca,cb);
            continue;
        }
        else{
            if(ask(ca|(1<<i),cb)==-1){
                ca|=(1<<i),cb|=(1<<i);
            }
        }
    }
    printf("! %d %d\n",ca,cb);
    fflush(stdout);
}