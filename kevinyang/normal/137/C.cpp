#include <bits/stdc++.h>

using namespace std;
pair<int,int> points[100010];
int bit[100010];
map<int,int> cc;
void update(int x,int p){
    for(;x<100010; x+=x&-x)bit[x]+=p;
}
int query(int x){
    int ret=0;
    for(;x;x-=x&-x)ret+=bit[x];
    return ret;
}
int query(int l,int r){
    return query(r)-query(l-1);
}
bool visited[100010];
int ccRee[100010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0,a,b; i<n; i++){
        scanf("%d %d",&a,&b);
        points[i]={a,b};
        // update(b,1);
        ccRee[i]=b;
    }
    sort(begin(ccRee),begin(ccRee)+n);
    for(int i=0; i<n; i++){
        cc[ccRee[i]]=i+1;
        update(cc[ccRee[i]],1);
    }
    int ans=0;
    sort(begin(points),begin(points)+n);
    int ma=0;
    for(int i=0; i<n; i++){
        pair<int,int> p = points[i];
        int ccP = cc[p.second];
        // update(ccP,-1);
        if(ccP>ma){
            int t=query(ccP-1);
            ans+=t;
            update(ccP,-t-1);
            ma=ccP;
        }
    }
    printf("%d\n",ans);

    return 0;
}