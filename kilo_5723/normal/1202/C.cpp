#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
multiset<int> st1,st2;
struct cplx{
    int x,y;
    cplx(int x=0,int y=0):x(x),y(y){}
};
const cplx nan(1e9,1e9),d[4]={cplx(0,1),cplx(1,0),cplx(0,-1),cplx(-1,0)};
inline cplx operator + (const cplx &a,const cplx &b){ return cplx(a.x+b.x,a.y+b.y); }
inline bool operator == (const cplx &a,const cplx &b){
    return a.x==b.x&&a.y==b.y;
}
void add(const cplx &n){
    st1.insert(n.x);
    st2.insert(n.y);
}
void del(const cplx &n){
    if (n==nan) return;
    st1.erase(st1.find(n.x));
    st2.erase(st2.find(n.y));
}
cplx a[maxn],b[maxn];
char s[maxn];
int n;
void init(){
    st1.clear(); st2.clear();
    for (int i=0;i<=n;i++) add(b[i]=a[i]);
}
inline ll calc(){
    multiset<int>::iterator it;
    int x1=*st1.begin(),x2,y1=*st2.begin(),y2;
    it=st1.end(); it--; x2=*it;
    it=st2.end(); it--; y2=*it;
    return (ll)(x2-x1+1)*(y2-y1+1);
}
inline cplx get(char ch){
    switch (ch){
        case 'W': return d[3];
        case 'A': return d[2];
        case 'S': return d[1];
        case 'D': return d[0];
        default: return nan;
    }
}
int main(){
    int tt;
    int i,k;
    cplx cur;
    ll ans;
    scanf("%d",&tt);
    while (tt--){
        scanf("%s",s);
        for (i=0;s[i];i++) a[i+1]=a[i]+get(s[i]);
        n=i;
  //      for (i=0;i<=n;i++) printf("(%d,%d) ",a[i].x,a[i].y);
   //     puts("");
        init(); ans=calc();
  //      for (auto ttt:st1) cout<<ttt<<' ';
  //      cout<<endl;
  //      for (auto ttt:st2) cout<<ttt<<' ';
  //     cout<<endl;
        for (k=0;k<4;k++){
            cur=nan;
            init();
            for (i=n;i;i--){
                del(cur); del(b[i]);
                b[i]=b[i]+d[k]; cur=b[i-1]+d[k];
                add(cur); add(b[i]);
                ans=min(ans,calc());
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}