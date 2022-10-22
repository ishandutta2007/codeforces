#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int cnt[33];
int n;
void init(){
    memset(cnt, 0, sizeof cnt);
    cin>>n;
    fors(i,0,n){
        int x; scanf("%d", &x);
        for(int j = 0; j < 30; ++j) {
            if(x>>j&1) cnt[j]++;
        }
    }
}
void sol(){
    for(int i = 1; i <= n; ++i){
        int ok = 1;
        for(int j = 0; j < 30; ++j) if(cnt[j]%i) ok = 0;
        if(ok) printf("%d ",i);
    }printf("\n");
}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}