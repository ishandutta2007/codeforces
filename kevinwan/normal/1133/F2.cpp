#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=2e5+10;
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
vector<pii>v,one;
vector<pii>ans;
bool done[mn];
int main(){
    int n,m,d,i,a,b;
    scanf("%d%d%d",&n,&m,&d);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        if(a==1)one.push_back({1,b});
        else v.push_back({a,b});
    }
    iota(p,p+mn,0);
    for(pii e:v){
        if(f(e.first)!=f(e.second)){
            p[f(e.first)]=f(e.second);
        }
    }
    set<int>s;
    for(pii e:one){
        if(s.find(f(e.second))==s.end()){
            s.insert(f(e.second));
            v.push_back({1,e.second});
            done[e.second]=1;
            d--;
        }
    }
    if(d<0){
        printf("NO");
        return 0;
    }
    for(pii e:one){
        if(done[e.second])continue;
        if(d)v.push_back({1,e.second}),d--;
    }
    if(d){
        printf("NO");
        return 0;
    }
    reverse(v.begin(),v.end());
    iota(p,p+mn,0);
    for(pii e:v){
        if(f(e.first)!=f(e.second)){
            p[f(e.first)]=f(e.second);
            ans.push_back(e);
        }
    }
    if(ans.size()!=n-1){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(pii e:ans)printf("%d %d\n",e.first,e.second);
}