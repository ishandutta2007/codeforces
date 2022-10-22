#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=1e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{
    int id,k;
    vector<int>x;
    bool operator <(node i)const{
        return k<i.k;
    }
}a[maxm],suf[maxm];
int b[maxm];
int c[maxn];
int t[maxn];
int main(){
    int T;
    T=read();
    while(T--){
        int n,m;
        n=read();m=read();
        for(int i=1;i<=m;i++){
            a[i].id=i;
            a[i].k=read();
            a[i].x.clear();a[i].x.resize(a[i].k);
            for(int j=0;j<a[i].k;j++)a[i].x[j]=read();
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=n;i++)t[i]=0;
        for(int i=m;i>=1;i--){
            suf[i].x.resize(a[i].k);
            for(int j=0;j<a[i].k;j++){
                suf[i].x[j]=t[a[i].x[j]];
                t[a[i].x[j]]++;
            }
        }
        for(int i=1;i<=n;i++)c[i]=0;
        bool flag=0;
        for(int i=1;i<=m;i++){
            int mn=m+1,p=0,s=m+1;
            for(int j=0;j<a[i].k;j++){
                if(mn>c[a[i].x[j]])p=a[i].x[j],mn=c[a[i].x[j]],s=suf[i].x[j];
                else if(mn==c[a[i].x[j]]&&suf[i].x[j]<s)p=a[i].x[j],s=suf[i].x[j];
            }
            b[a[i].id]=p;
            c[p]++;
            if(c[p]>(m+1)/2){flag=1;break;}
        }
        if(flag)puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=m;i++)printf("%d ",b[i]);
            puts("");
        }
        for(int i=1;i<=m;i++){vector<int>().swap(a[i].x);vector<int>().swap(suf[i].x);}
    }
    return 0;
}