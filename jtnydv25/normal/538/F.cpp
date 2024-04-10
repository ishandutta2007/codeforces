#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
const int N = 4e6;
int A[N];
set<int> s;
map<int, int> ind;
void compress(int n){
    for(int i = 1; i <= n; i++) s.insert(A[i]);
    int cnt = 0;
    for(int x : s) ind[x] = ++cnt;
    for(int i = 1; i <= n; i++) A[i] = ind[A[i]];
}
int lft[N],rgt[N],val[N], root[N], cnt = 0;
void push(int s, int e, int x, int pos1, int pos2){
    val[pos1] = val[pos2]+1;
    if(s==e) return;
    int mid = (s+e)/2;
    if(x<= mid){
        rgt[pos1] = rgt[pos2];
        lft[pos1] = ++cnt;
        pos2 = lft[pos2];
        pos1 = cnt;
        push(s,mid,x,pos1,pos2);
    }
    else{
        lft[pos1] = lft[pos2];
        rgt[pos1] = ++cnt;
        pos2 = rgt[pos2];
        pos1 = cnt;
        push(mid+1,e,x,pos1,pos2);
    }
}

// Number of elements lying between l and r, and having index <= i
int query(int s, int e, int l, int r, int ind){
    if(s>r || l>e) return 0;
    if(s>=l && e <= r) return val[ind];
    int mid = (s+e)>>1;
    return query(s,mid,l,r,lft[ind]) + query(mid+1,e,l,r,rgt[ind]);
}
// number of elements with indices between i and j inclusive, and values between l and r
inline int num_elements(int i, int j, int l, int r, int n){
    if(l > r) return 0;
    return query(0,n,l,r,root[j]) - query(0, n , l, r, root[i - 1]);
}
int main(){
    int n;
    sd(n);
    for(int i = 1; i <= n; i++) sd(A[i]);
    compress(n);
    for(int i = 1; i <= n; i++){
        root[i] = ++cnt;
        push(0, n, A[i], root[i], root[i - 1]);
    }
    for(int k = 1; k <= n - 1; k++){
        int ans = 0;
        for(int s = 1; (s - 1) *  k + 2 <= n; s++){
            int mn = (s - 1) * k + 2, mx = min(n, k * s + 1);
            ans += num_elements(mn, mx, 0, A[s] - 1, n);
        }
        printf("%d ", ans);
    }
}