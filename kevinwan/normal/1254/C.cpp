#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=1e3+10;
bool ccw(int a,int b,int c){
    printf("2 %d %d %d\n",a,b,c);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x==1;
}
ll area(int a,int b,int c){
    printf("1 %d %d %d\n",a,b,c);
    fflush(stdout);
    ll x;
    scanf("%lld",&x);
    return x;
}
ll k[mn];
int ord[mn];
bool comp(int a,int b){return k[a]<k[b];}
int main(){
    int n;
    scanf("%d",&n);
    int sm=2;
    for(int i=3;i<=n;i++){
        if(!ccw(1,sm,i))sm=i;
    }
    for(int i=2;i<=n;i++){
        if(i==sm)continue;
        k[i]=area(1,sm,i);
    }
    iota(ord+1,ord+n+1,1);
    sort(ord+1,ord+n+1,comp);
    deque<int>hail;
    hail.push_back(1);
    hail.push_back(sm);
    int i,j;
    for(i=3,j=4;i<=n&&j<=n;){
        if(ccw(1,ord[i],ord[j]))hail.push_back(ord[i]);
        else hail.push_front(ord[i]);
        i++,j++;
    }
    hail.push_back(ord[n]);
    while(hail.front()!=1)hail.push_back(hail.front()),hail.pop_front();
    printf("0 ");
    for(int x:hail)printf("%d ",x);
    printf("\n");
    fflush(stdout);
}