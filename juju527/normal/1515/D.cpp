#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int tl[maxn],tr[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n,l,r;
        n=read();l=read();r=read();
        for(int i=1;i<=n;i++)tl[i]=tr[i]=0;
        for(int i=1;i<=l;i++)tl[read()]++;
        for(int i=1;i<=r;i++)tr[read()]++;
        int vl=0,vr=0,res=0,numl=0,numr=0;
        for(int i=1;i<=n;i++){
            if(tl[i]==tr[i])continue;
            int val=abs(tl[i]-tr[i]);
            if(tl[i]>tr[i])numl+=val/2*2;
            else numr+=val/2*2;
            res+=val/2;
            if(val&1){
                if(tl[i]>tr[i])vl++;
                else vr++;
            }
        }
        int val=min(vl,vr);
        res+=val;vl-=val;vr-=val;
        if(vl){
            res+=min(vl/2,numr/2);
            vl-=min(vl/2,numr/2)*2;
            res+=vl;
        }
        if(vr){
            res+=min(vr/2,numl/2);
            vr-=min(vr/2,numl/2)*2;
            res+=vr;
        }
        printf("%d\n",res);
    }
    return 0;
}