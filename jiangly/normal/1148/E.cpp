#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN=300000;
int n,m;
pair<int,int>s[MAXN];
int t[MAXN];
pair<int,int>st[MAXN];
int top;
tuple<int,int,int>op[MAXN*5];
void kill(){
    puts("NO");
    exit(0);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&s[i].first);
        s[i].second=i;
    }
    for(int i=0;i<n;++i)
        scanf("%d",&t[i]);
    sort(s,s+n);
    sort(t,t+n);
    for(int i=0;i<n;++i)
        t[i]-=s[i].first;
    ll sum=0;
    for(int i=0;i<n;++i){
        sum+=t[i];
        if(sum<0)
            kill();
    }
    if(sum!=0)
        kill();
    for(int i=0;i<n;++i){
        if(t[i]>0)
            st[top++]={i,t[i]};
        else
            for(int r=-t[i];r>0;){
                int d=min(r,st[top-1].second);
                op[m++]={s[st[top-1].first].second,s[i].second,d};
                r-=d;
                st[top-1].second-=d;
                if(st[top-1].second==0)
                    --top;
            }
    }
    puts("YES");
    printf("%d\n",m);
    for(int i=0;i<m;++i)
        printf("%d %d %d\n",get<0>(op[i])+1,get<1>(op[i])+1,get<2>(op[i]));
    return 0;
}