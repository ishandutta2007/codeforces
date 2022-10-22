#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int ans[mn];
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(abs(a+c-b-d)>1)printf("NO");
    else if(a+c-b-d==1){
        for(int i=0;i<a;i++)ans[i*2]=0;
        for(int i=a;i<a+c;i++)ans[i*2]=2;
        for(int i=0;i<b;i++)ans[i*2+1]=1;
        for(int i=b;i<b+d;i++)ans[i*2+1]=3;
        for(int i=0;i<a+b+c+d-1;i++)if(abs(ans[i]-ans[i+1])!=1)goto veshy1;
        printf("YES\n");
        for(int i=0;i<a+b+c+d;i++)printf("%d ",ans[i]);
        return 0;
        veshy1:
        printf("NO\n");
    }
    else{
        for(int i=0;i<a;i++)ans[i*2+1]=0;
        for(int i=a;i<a+c;i++)ans[i*2+1]=2;
        for(int i=0;i<b;i++)ans[i*2]=1;
        for(int i=b;i<b+d;i++)ans[i*2]=3;
        for(int i=0;i<a+b+c+d-1;i++)if(abs(ans[i]-ans[i+1])!=1)goto veshy2;
        printf("YES\n");
        for(int i=0;i<a+b+c+d;i++)printf("%d ",ans[i]);
        return 0;
        veshy2:
        for(int i=0;i<c;i++)ans[i*2+1]=2;
        for(int i=c;i<a+c;i++)ans[i*2+1]=0;
        for(int i=0;i<d;i++)ans[i*2]=3;
        for(int i=d;i<b+d;i++)ans[i*2]=1;
        for(int i=0;i<a+b+c+d-1;i++)if(abs(ans[i]-ans[i+1])!=1)goto veshy3;
        printf("YES\n");
        for(int i=0;i<a+b+c+d;i++)printf("%d ",ans[i]);
        return 0;
        veshy3:
        printf("NO\n");
    }
}