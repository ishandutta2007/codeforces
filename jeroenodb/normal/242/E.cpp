#include <iostream>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1<<18, mxB = 20;
int lazy[mxN]={}, ones[mxN][mxB]={};
void pullup(int i,int l, int r) {
    int sz = (r-l+1)/2;
    for(int j=0;j<mxB;++j) {
        if(lazy[i*2] &(1<<j)) {
            ones[i][j] = sz-ones[i*2][j];
        } else {
            ones[i][j] = ones[i*2][j];
        }
        if(lazy[i*2+1] & (1<<j)) {
            ones[i][j] += sz-ones[i*2+1][j];
        } else {
            ones[i][j] += ones[i*2+1][j];
        }
    }

}
void pushdown(int i) {
    lazy[i*2]^=lazy[i];
    lazy[i*2+1]^=lazy[i];
    lazy[i]=0;
}
void update(int i, int l, int r, int a, int b,int x) {
    if(a<=l and r <= b) {
        lazy[i]^= x;
        return;
    }
    int mid = (l+r)/2;
    pushdown(i);
    if(a<=mid) {
        update(i*2,l,mid,a,b,x);
    }
    if(b>=mid+1) {
        update(i*2+1,mid+1,r,a,b,x);
    }
    pullup(i,l,r);
}

long long sum(int i, int l, int r, int a, int b) {
    long long ans=0;
    if(a<=l and r <= b) {
         for(int j=0;j<mxB;++j) {
            int tmp = ones[i][j];
            if(lazy[i] & (1<<j)) tmp = (r-l+1)-tmp;
            ans+=(1LL<<j) * tmp;
        }
        return ans;
    }
    int mid = (l+r)/2;
    pushdown(i);
    pullup(i,l,r);
    if(a<=mid) {
        ans+=sum(i*2,l,mid,a,b);
    }
    if(b>=mid+1) {
        ans+=sum(i*2+1,mid+1,r,a,b);
    }
    return ans; 
}
int Pow=1,n;
void build(int i, int l, int r) {
    int mid = (l+r)/2;
    if(i<Pow) {
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        pullup(i,l,r);
    }
}

int main() {
    cin >> n;
    while(Pow<n) Pow*=2;
    for(int i=0;i<n;++i) {
        int cur; cin >> cur;
        for(int j=0;j<mxB;++j) {
            ones[i+Pow][j] = !!(cur &(1<<j));
        }
    }

    build(1,0,Pow-1);
    int m; cin >> m;
    while(m--) {
        int q,l,r; cin >> q >> l >> r;
        l--, r--;
        if(q==1) {
            cout << sum(1,0,Pow-1,l,r) << endl;
        } else {
            int x; cin >> x;
            update(1,0,Pow-1,l,r,x);
        }
    }
}