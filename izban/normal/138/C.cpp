#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

const int maxn=100000,maxm=10000;

struct tree {
        int a,h;
        double l,r;
} a[maxn],a2[maxn];

struct mushroom {
        int b;
        double z;
        bool operator<(const mushroom &m) {
                return b<m.b;
        }
} b[maxm];


int n,m,k,p;
string s;
double ans;
double t[4*maxm];


void edit(int x, int tl, int tr, int l, int r, double d) {
        if (l>r) return;
        if (tl==l && tr==r) {
                t[x]*=d;
                return;
        }
        int tm=(tl+tr)/2;
        edit(x*2,tl,tm,l,min(tm,r),d);
        edit(x*2+1,tm+1,tr,max(tm+1,l),r,d);
}

double get(int x, int tl, int tr, int pos) {
        if (tl==tr) return t[x];
        int tm=(tl+tr)/2;
        if (tm>=pos) return t[x]*get(x*2,tl,tm,pos);
        else return t[x]*get(x*2+1,tm+1,tr,pos);
}


int upper(int l, int r, int x, bool f) {
        while (r-l>1) {
                int m=(l+r)/2;
                if (b[m].b<x) l=m;
                if (b[m].b>x) r=m;
                if (b[m].b==x && f) r=m;
                if (b[m].b==x && !f) l=m;
        }
        //if ((b[l].b==x && f)||(b[l].b>x)) return l; else return r;
        if (b[l].b>x || (b[l].b==x && f)) return l;
        if (b[r].b>x || (b[r].b==x && f)) return r;
        return -1;
}

int lower(int l, int r, int x, bool f) {
        while (r-l>1) {
                int m=(l+r)/2;
                if (b[m].b<x) l=m;
                if (b[m].b>x) r=m;
                if (b[m].b==x && f) l=m;
                if (b[m].b==x && !f) r=m;
        }
        //if ((b[r].b==x && f)||(b[r].b<x)) return r; else return l;
        if (b[r].b<x || (b[r].b==x && f)) return r;
        if (b[l].b<x || (b[l].b==x && f)) return l;
        return -1;
}

int main() {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
        cin >> n >> m;
        for (int i=0; i<n; i++) scanf("%d%d%lf%lf",&a[i].a,&a[i].h,&a[i].l,&a[i].r);
        for (int i=0; i<n; i++) { a[i].l/=100.0; a[i].r/=100.0; }
        for (int i=0; i<m; i++) scanf("%d%lf",&b[i].b,&b[i].z);
        sort(b,b+m);
        for (int i=0; i<4*maxm; i++) t[i]=1;
        for (int i=0; i<n; i++) {
                int l,r;

                l=upper(0,m-1,a[i].a-a[i].h,true);
                r=lower(0,m-1,a[i].a,false);
                if (l!=-1 && r!=-1) edit(1,0,m-1,l,r,1.0-a[i].l);

                l=upper(0,m-1,a[i].a,false);
                r=lower(0,m-1,a[i].a+a[i].h,true);
                if (l!=-1 && r!=-1) edit(1,0,m-1,l,r,1.0-a[i].r);
        }
        for (int i=0; i<m; i++) {
                ans+=b[i].z*get(1,0,m-1,i);
        }
        printf("%.10lf",ans);

        return 0;
}