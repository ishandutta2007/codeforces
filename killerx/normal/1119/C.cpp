#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N][N];
set<int>row[N],col[N];
set<pair<int,int> >st;
void no(){puts("No");exit(0);}
void op(int i,int j){
    a[i][j]^=1;
    if(a[i][j]){
        row[i].insert(j);
        col[j].insert(i);
        st.insert(make_pair(i,j));
    }else{
        row[i].erase(j);
        col[j].erase(i);
        st.erase(make_pair(i,j));
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int x;scanf("%d",&x);
            a[i][j]^=x;
            if(a[i][j]){
                st.insert(make_pair(i,j));
                row[i].insert(j);
                col[j].insert(i);
            }
        }
    }
    while(!st.empty()){
        pair<int,int>p=*st.begin();
        st.erase(st.begin());
        int i=p.first,j=p.second;
        int ni,nj;
        for(ni=i+1;ni<=n&&!row[ni].count(j);++ni);
        for(nj=j+1;nj<=m&&!col[nj].count(i);++nj);
        if(ni>n||nj>m)no();
        op(i,j);op(ni,j);op(i,nj);op(ni,nj);
    }
    puts("Yes");
    return 0;
}