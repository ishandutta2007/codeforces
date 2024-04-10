#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=1e5+5;
int cnt1[maxn],cnt2[maxn];
struct cplx{
    int x,y;
    cplx(int x=0,int y=0):x(x),y(y){}
};
bool operator < (const cplx &a,const cplx &b){
    if (a.x!=b.x) return a.x<b.x;
    if (a.y!=b.y) return a.y<b.y;
    return false;
}
set<cplx> st;
int main(){
    int i,j,n,m,k;
    int x,y;
    int l1,r1,l2,r2;
    bool flg;
    scanf("%d%d%d",&n,&m,&k);
    while (k--){
        scanf("%d%d",&x,&y);
        cnt1[x]++; cnt2[y]++;
        st.insert(cplx(x,y));
    }
    l1=1; r1=n; l2=1; r2=m; x=0; y=0;
    while (true){
        if (st.count(cplx(l1,l2))) break;
        while (l2<=r2&&cnt2[r2]==n){ r2--; y++; }
        if (l2>r2) break;
        if (cnt1[l1]!=y){ puts("No"); return 0; }
        n--; l1++;
        if (st.count(cplx(l1,r2))) break;
        while (l1<=r1&&cnt1[r1]==m){ r1--; x++; }
        if (l1>r1) break;
        if (cnt2[r2]!=x){ puts("No"); return 0; }
        m--; r2--;
        if (st.count(cplx(r1,r2))) break;
        while (l2<=r2&&cnt2[l2]==n){ l2++; y++; }
        if (l2>r2) break;
        if (cnt1[r1]!=y){ puts("No"); return 0; }
        n--; r1--;
        if (st.count(cplx(r1,l2))) break;
        while (l1<=r1&&cnt1[l1]==m){ l1++; x++; }
        if (l1>r1) break;
        if (cnt2[l2]!=x){ puts("No"); return 0; }
        m--; l2++;
    }
  //  cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
    for (i=l1;i<=r1;i++) for (j=l2;j<=r2;j++)
        if (!st.count(cplx(i,j))){
            puts("No"); return 0;
        }
    puts("Yes");
    return 0;
}