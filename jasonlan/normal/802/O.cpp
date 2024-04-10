#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=501010;
typedef long long ll;
typedef pair<int,int> node;
int n,k;
int a[maxn],b[maxn];
ll s;
int cnt;
priority_queue <node> q;
void Check(int d){
    s=0;cnt=0;
    for(int i=1;i<=n;++i){
        q.push(make_pair(d-a[i],0));
        int tmp=b[i]-q.top().first;
        if(tmp<0){
            s+=tmp;
            if(!q.top().second)++cnt;
            q.pop();
            q.push(make_pair(b[i],1));
        }
    }
    while(q.size())q.pop();
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<=n;++i)scanf("%d",b+i);
    long long l=0,r=2e9,mid;
    while(l<r){
        mid=(l+r)>>1;
        Check(mid);
        if(cnt<k)l=mid+1;
        else r=mid;
    }
    Check(l);
    printf("%lld\n",s+1ll*l*k);
    return 0;
}