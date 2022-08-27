#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
#define inf 1000000000000000ll
using namespace std;
typedef long long ll;
int n;
struct node{int t,s,p,i;}a[50005];
int x;
int cmpp(const node&a,const node&b){return a.p<b.p;}
int cmpt(const node&a,const node&b){return a.t<b.t;}
int arr[50005],arrtot=0;
ll T;
ll fin[50005];

int lef[50005];
struct cmp{
    int operator()(int i,int j){
        return a[i].p<a[j].p;
    }
};
priority_queue<int,vector<int>,cmp> qu;
ll check(int p){
    int cur=1;
    ll curt=0;
    while(1){
        while(cur<=n&&a[cur].t==curt){
            if(a[cur].i==x)a[cur].p=p;
            lef[cur]=a[cur].s;
            qu.push(cur);
            cur++;
        }
        ll finthis=inf;
        if(!qu.empty())finthis=curt+lef[qu.top()];
        ll nexcome=inf;
        if(cur<=n)nexcome=a[cur].t;
        ll del=min(nexcome,finthis);
        if(del==inf)break;del-=curt;
        if(!qu.empty()){
            if((lef[qu.top()]-=del)==0){
                fin[a[qu.top()].i]=curt+del;
                qu.pop();
            }
        }
        curt+=del;
    }
    return fin[x];
}
int main()
{
freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].t,&a[i].s,&a[i].p),a[i].i=i;
    for (int i=1;i<=n;i++)if(a[i].p==-1)x=i;
    sort(a+1,a+1+n,cmpp);
    cin>>T;
    if(a[2].p!=1)arr[++arrtot]=1;
    for (int i=2;i<n;i++)if(a[i].p!=a[i+1].p-1)arr[++arrtot]=a[i].p+1;
    if(a[n].p!=1000000000)arr[++arrtot]=a[n].p+1;
    sort(a+1,a+1+n,cmpt);
    int l=1,r=arrtot,mid;
    while(l<=r){
        mid=l+r>>1;
        ll t=check(arr[mid]);
        if(t>T)l=mid+1;
        else if(t<T)r=mid-1;
        else {
            printf("%d\n",arr[mid]);
            for (int i=1;i<=n;i++){
                if(i>1)printf(" ");
                cout<<fin[i];
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}