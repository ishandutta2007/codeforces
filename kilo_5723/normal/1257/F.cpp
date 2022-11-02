#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int maxn=105,base=1<<15;
int a[maxn];
struct arr{
    int val;
    int a[maxn];
    arr(){ memset(a,0,sizeof(a)); }
};
bool operator < (const arr &a,const arr &b){
    for (int i=0;i<maxn;i++) if (a.a[i]!=b.a[i])
        return a.a[i]<b.a[i];
    return false;
}
int bit[base];
arr b[base];
set<arr> st;
int main(){
    int i,j,n;
    arr tmp;
    bit[0]=0;
    for (i=1;i<base;i++) bit[i]=bit[i>>1]+(i&1);
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (j=0;j<base;j++){
        for (i=0;i<n;i++) b[j].a[i]=-bit[(a[i]>>15)^j];
        for (i=1;i<n;i++) b[j].a[i]-=b[j].a[0];
        b[j].a[0]=0;
    }
    for (j=0;j<base;j++){
        tmp.val=j;
        for (i=0;i<n;i++) tmp.a[i]=bit[(a[i]&(base-1))^j];
        for (i=1;i<n;i++) tmp.a[i]-=tmp.a[0];
        tmp.a[0]=0;
        st.insert(tmp);
    }
    for (i=0;i<base;i++) if (st.count(b[i])){
        set<arr>::iterator it=st.find(b[i]);
        printf("%d\n",(i<<15)+it->val);
        return 0;;
    }
    puts("-1");
    return 0;
}