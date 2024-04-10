#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=1e5+5;
struct trip{
    int a,b,c;
    trip(int a,int b,int c):a(a),b(b),c(c){}
};
bool operator < (const trip &a,const trip &b){
    if (a.a!=b.a) return a.a<b.a;
    if (a.b!=b.b) return a.b<b.b;
    if (a.c!=b.c) return a.c<b.c;
    return false;
}
set<trip> tri[maxn];
set<trip> st;
set<int> id;
int main(){
    int i,n;
    int a,b,c,t;
    trip tp(0,0,0);
    scanf("%d",&n);
    for (i=0;i<n-2;i++){
        scanf("%d%d%d",&a,&b,&c);
        tri[a].insert(trip(a,b,c));
        tri[b].insert(trip(a,b,c));
        tri[c].insert(trip(a,b,c));
    }
    for (i=1;i<=n;i++) id.insert(i);
    for (i=1;i<=n;i++) if (tri[i].size()==1) t=i;
    tp=*tri[t].begin();
    a=tp.a; b=tp.b; c=tp.c;
    if (tri[a].size()==2) tri[a].insert(trip(0,0,0));
    if (tri[b].size()==2) tri[b].insert(trip(0,0,0));
    if (tri[c].size()==2) tri[c].insert(trip(0,0,0));
    for (i=1;i<=n;i++) if (i!=t) st.insert(trip(tri[i].size(),i,0));
    while (st.size()){
        a=st.begin()->b;
        tp=*tri[a].begin();
        printf("%d ",a); id.erase(a);
        a=tp.a; b=tp.b; c=tp.c;
        if (!a) break;
        st.erase(trip(tri[a].size(),a,0));
        st.erase(trip(tri[b].size(),b,0));
        st.erase(trip(tri[c].size(),c,0));
        tri[a].erase(tp);
        tri[b].erase(tp);
        tri[c].erase(tp);
        st.insert(trip(tri[a].size(),a,0));
        st.insert(trip(tri[b].size(),b,0));
        st.insert(trip(tri[c].size(),c,0));
        while (st.size()&&!st.begin()->a) st.erase(st.begin());
    }
    id.erase(t);
    printf("%d\n",t);
    return 0;
}