#include<bits/stdc++.h>
using namespace std;
const int N=66666;
int n,f[N],T,a[N];
char str[N];
struct node{
    char ch;int id;
}s[N],t[N];
bool cmp(node a,node b){return a.ch<b.ch;}
int main(){
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=1;i<=n;i++)s[i]=(node){str[i-1],i};
    sort(s+1,s+n+1,cmp);
    scanf("%s",str);
    for(int i=1;i<=n;i++)t[i]=(node){str[i-1],i};
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(s[i].ch!=t[i].ch){
            printf("-1");
            return 0;
        }
        f[s[i].id]=t[i].id;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)if(f[j]>f[j+1])a[++T]=j,swap(f[j],f[j+1]);
    }
    printf("%d\n",T);
    for(int i=1;i<=T;i++)printf("%d ",a[i]);
    return 0;
}