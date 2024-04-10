#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
struct item {
    int c,v,p;
    item(){}
    item(const int &_c,const int &_v,const int &_p) {
        c=_c;v=_v;p=_p;
    }
    bool operator < (const item &x) const {
        if (v*x.c>c*x.v) return (true);
        if (v*x.c<c*x.v) return (false);
        return (c>x.c);
    }
};
item a[MAX];
bool e[MAX];
int n,m,maxv,used;
vector<int> chs;
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    int i,c,v;
    used=0;
    maxv=0;
    for (i=1;i<=n;i=i+1) {
        scanf("%d",&c);
        scanf("%d",&v);
        a[i]=item(c,v,i);
        used=used+c;
        maxv=maxv+v;        
    }
    if (used<=m) {
        printf("%d\n",maxv);
        for (i=1;i<n;i=i+1) printf("%d ",i);
        printf("%d",n);
        exit(0);
    }
    sort(&a[1],&a[n+1]);
}
void choose(void) {
    chs.clear();
    maxv=0; 
    used=0;
    int i,j;
    for (i=1;i<=n;i=i+1)
        if (used+a[i].c<=m) {
            e[i]=true;
            chs.push_back(i);
            maxv=maxv+a[i].v;
            used=used+a[i].c;
        }
    if (used==m) return;
    for (i=(int)chs.size()-1;i>=0;i=i-1)
        if (a[chs[i]].c==1) break;
    if (i<0) return;
    for (j=1;j<=n;j=j+1)
        if (!e[j]) break;
    if (a[chs[i]].v<a[j].v) {
        maxv=maxv+a[j].v-a[chs[i]].v;
        chs[i]=j;
    }
}
void print(void) {
    int i;
    printf("%d\n",maxv);
    if (chs.empty()) return;
    printf("%d",a[chs[0]].p);
    for (i=1;i<chs.size();i=i+1) printf(" %d",a[chs[i]].p);
}
int main(void) {
    init();
    choose();
    print();
    return 0;
}