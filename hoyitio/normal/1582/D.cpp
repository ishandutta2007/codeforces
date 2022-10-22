#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5+5;
int a[maxn], n;
void init(){
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]);
}
const int N = 1e4+5;
int b[maxn];
void sol(){
    if(n%2 == 0){
        fors(i,1,n+1) b[i]=a[n+1-i];
        for(int i = 1; i <= n/2; ++i) b[i] =  -b[i];
        fors(i,1,n+1) printf("%d ",b[i]); printf("\n"); return;
    }

//    {
        int m = (n+1)/2;
        fors(i,1,n+1) {
            int t1 = abs(a[i]), t2 = abs(a[n+1-i]);
            b[i]=a[n+1-i];
        }
        for(int i = 1; i <= n/2; ++i) b[i] =  -b[i];
        int x = a[m-1], y = a[m], z = a[m+1];
        if(y+z == 0){
            b[m-1] = y-z;
            b[m]= -x;
            b[m+1] = x;
        }else{
            b[m-1] = y+z;
            b[m] = -x;
            b[m+1] = -x;
        }
        fors(i,1,n+1) printf("%d ", b[i]); printf("\n");
//    }

}
int main(){
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
    return 0;
}
/*
1
5
5 4 10 -9 -2
*/