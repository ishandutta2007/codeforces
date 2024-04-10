#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define mo 1000000009
using namespace std;

int n,h;
#define id(a,b,c,i) ((a)<<11|(b)<<6|(c)<<1|(i))
int f[1001][65536]={0};
inline void upd(int &x,int v){x=(x+v>=mo?x+v-mo:x+v);}
int main()
{
    scanf("%d%d",&n,&h);
    f[0][id(0,0,0,0)]=1;
    int tmp;
    for (int t=0;t<n;t++)
        for (int a=0;a<=h;a++)
            for (int b=a;b<=h;b++)
                for (int c=b;c<=h;c++){
                    if(tmp=f[t][id(a,b,c,0)]){
                        if(c==h-1){
                            upd(f[t+1][id(0,a+1,b+1,1)],tmp);
                            upd(f[t+1][id(0,1,b+1,1)],tmp);
                            upd(f[t+1][id(0,1,a+1,1)],tmp);
                        }else{
                            upd(f[t+1][id(a+1,b+1,c+1,0)],tmp);
                            upd(f[t+1][id(1,b+1,c+1,0)],tmp);
                            upd(f[t+1][id(1,a+1,c+1,0)],tmp);
                        }
                        if(b==h-1){
                            upd(f[t+1][id(0,1,a+1,1)],tmp);
                        }else upd(f[t+1][id(1,a+1,b+1,0)],tmp);
                    }
                    if(tmp=f[t][id(a,b,c,1)]){
                        int k=1;
                        if(c==h)k++;
                        else upd(f[t+1][id(0,a==h?h:a+1,b==h?h:b+1,1)],tmp);
                        if(b==h)k++;
                        else upd(f[t+1][id(0,a==h?h:a+1,c==h?h:c+1,1)],tmp);
                        if(a==h)k++;
                        else upd(f[t+1][id(0,b==h?h:b+1,c==h?h:c+1,1)],tmp);
                        if(k==4)continue;
                        upd(f[t+1][id(a==h?h:a+1,b==h?h:b+1,c==h?h:c+1,1)],1ll*tmp*k%mo);
                    }
                }
    int ans=0;
    for (int a=0;a<=h;a++)
            for (int b=a;b<=h;b++)
                for (int c=b;c<=h;c++){
                    upd(ans,f[n][id(a,b,c,0)]);
                    if(a!=h)upd(ans,f[n][id(a,b,c,1)]);
                }
    printf("%d\n",ans);
    return 0;
}