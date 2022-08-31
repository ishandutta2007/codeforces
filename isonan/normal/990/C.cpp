#include <cstdio>
#include <iostream>

long long left[300001],right[300001],n,ans;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        int t1=0,t2=0;
        char ch=getchar();
        while(ch!='\n'){
            if(ch=='(')t2++;
            else{
                if(t2)t2--;
                else t1++;
            }
            ch=getchar();
        }
        if(t1&&t2)continue;
        if(!t2)left[t1]++;
        if(!t1)right[t2]++;
    }
    for(int i=0;i<=300000;i++)ans+=left[i]*right[i];
    std::cout<<ans;
}