// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int MAXN=300000;
int n;
pair<int,int>p[MAXN];
int cnta,cntb;
int a[MAXN],b[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&p[i].first,&p[i].second);
        if(p[i].first<p[i].second)
            a[cnta++]=i;
        else
            b[cntb++]=i;
    }
    sort(a,a+cnta,[](int i,int j){return p[i]>p[j];});
    sort(b,b+cntb,[](int i,int j){return p[i]<p[j];});
    printf("%d\n",max(cnta,cntb));
    if(cnta>cntb)
        for(int i=0;i<cnta;++i)
            printf("%d ",a[i]+1);
    else
        for(int i=0;i<cntb;++i)
            printf("%d ",b[i]+1);
    return 0;
}