#include<bits/stdc++.h>
using namespace std;
const int mn=150;
struct edge{int a,b,c;};
bitset<mn>t[mn],u,v[mn];
bitset<mn>bas[30][mn],cur;
void mult(bitset<mn>c[mn],bitset<mn>a[mn],bitset<mn>b[mn]){
    memcpy(v,b,sizeof(v));
    for(int i=0;i<mn;i++)for(int j=i+1;j<mn;j++){
        bool b=v[i][j];
        v[i][j]=v[j][i];
        v[j][i]=b;
    }
    for(int i=0;i<mn;i++)for(int j=0;j<mn;j++)t[i][j]=(a[i]&v[j]).count()>0;
    memcpy(c,t,sizeof(t));
};
void mult(bitset<mn>&c,bitset<mn>a[mn],bitset<mn>b){
    for(int i=0;i<mn;i++)u[i]=(a[i]&b).count()>0;
    c=u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<edge>v;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a-1,b-1,c});
    }
    v.push_back({0,0,0x3f3f3f3f});
    cur[0]=1;
    bas[0][n-1][n-1]=1;
    sort(v.begin(),v.end(),[](auto a,auto b){return a.c<b.c;});
    if(v[0].c){printf("Impossible");return 0;}
    for(int i=0;i<v.size()-1;i++){
        bas[0][v[i].b][v[i].a]=1;
        if(v[i].c==v[i+1].c)continue;
        int num=v[i+1].c-v[i].c;
        int lev=31-__builtin_clz(num);
        for(int i=1;i<=lev;i++)mult(bas[i],bas[i-1],bas[i-1]);
        int bs=0;
        bitset<mn>pig;
        for(int i=lev;i>=0;i--){
            if(bs+(1<<i)>num)continue;
            mult(pig,bas[i],cur);
            if(!pig[n-1])cur=pig,bs+=1<<i;
        }
        if(bs!=num){
            printf("%d",v[i].c+bs+1);
            return 0;
        }
    }
    printf("Impossible");
}