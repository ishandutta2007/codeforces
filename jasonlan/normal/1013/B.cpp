#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,d1[101000],d2[101000];
inline int read(){
    int res=0;
    char ch=getchar(),flag=ch;
    while(ch<'0'||ch>'9')flag=ch,ch=getchar();
    while(ch>='0'&&ch<='9')
        res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return flag=='-'?-res:res;
}
int main()
{
    n=read();k=read();
    for(register int i=0,x;i<n;++i){
        x=read();
        ++d1[x];
        if((x&k)!=x)++d2[x&k];
    }
    int ans=3;
    for(register int i=0;i<=100000;++i)
        if(d1[i]+d2[i]>=2){
            if(d1[i]>=2){ans=0;break;}
            else if(d1[i]==1)ans=1;
            else ans=min(ans,2);
        }
    if(ans==3)ans=-1;
    printf("%d",ans);
	return 0;
}