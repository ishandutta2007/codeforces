#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, M;
struct data{
    int A, B, val;
    bool operator<(const data&r)const{
        return val<r.val;
    }
}arr[NS];
map < int, int > cnt1, cnt2;
struct uni{
    int par, rk;
}un[NS];

int fd(int x){
    return x==un[x].par? x:un[x].par = fd(un[x].par);
}

void doun(int a, int b){
    int ra = fd(a), rb = fd(b);
    if(ra!=rb){
        if(un[ra].rk>=un[rb].rk){
            un[rb].par = ra, un[ra].rk += un[rb].rk;
        }
        else un[ra].par = rb, un[rb].rk += un[ra].rk;
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;++i){
        scanf("%d %d %d", &arr[i].A, &arr[i].B, &arr[i].val);
    }
    for(int i=1;i<=N;++i) un[i].par = i, un[i].rk = 1;
    sort(arr, arr+M);
    for(int i=0;i<M;++i){
        for(int j=i;arr[i].val==arr[j].val;++j){
            if(fd(arr[j].A)!=fd(arr[j].B)) ++cnt1[arr[i].val];
        }
        int j;
        for(j=i;arr[i].val==arr[j].val;++j){
            if(fd(arr[j].A)!=fd(arr[j].B)){
                ++cnt2[arr[i].val], doun(arr[j].A, arr[j].B);
            }
        }
        i = j-1;
    }
    map < int, int >::iterator p = cnt1.begin(), pp = cnt2.begin();
    int ans = 0;
    while(p!=cnt1.end()){
        ans += p->second-pp->second;
        ++p, ++pp;
    }
    printf("%d", ans);
    return 0;
}