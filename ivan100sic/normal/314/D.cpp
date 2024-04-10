#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct tacka{
    long long x,y;
    inline friend bool operator <(tacka a,tacka b){
        return a.x < b.x;
    }
};

long long N;
tacka A[100005];
long long Pmin[100005],Pmax[100005],Smin[100005],Smax[100005];

void ucitaj(){
    scanf("%I64d",&N);
    long long i,x,y;
    for (i=1; i<=N; i++){
        scanf("%I64d%I64d",&A[i].x,&A[i].y);
        x = A[i].x + A[i].y;
        y = A[i].x - A[i].y;
        A[i].x = x;
        A[i].y = y;
    }
}

bool proveri(long long w){
    long long l,r;
    r=1;
    for (l=1; l<=N; l++){
        while (r+1 <= N && A[r+1].x - A[l].x <= w) r++;
        if (max(Pmax[l-1] , Smax[r+1]) - min(Pmin[l-1] , Smin[r+1]) <= w || r-l==N-1) return true;
    }
    return false;
}

void resi(){
    long long i,l,r,m,o;
    l=0;
    r=20000000000ll;
    sort(A+1,A+N+1);
    Pmin[0] = 20000000001ll;
    Pmax[0] =-20000000001ll;
    for (i=1; i<=N; i++) Pmin[i] = min(Pmin[i-1] , A[i].y);
    for (i=1; i<=N; i++) Pmax[i] = max(Pmax[i-1] , A[i].y);
    Smin[N+1] = 20000000001ll;
    Smax[N+1] =-20000000001ll;
    for (i=N; i>=1; i--) Smin[i] = min(Smin[i+1] , A[i].y);
    for (i=N; i>=1; i--) Smax[i] = max(Smax[i+1] , A[i].y);
    while (l<=r){
        m = (l+r)/2;
        if (proveri(m)){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    printf("%.14lf\n",o*0.5);
}

int main(){
    ucitaj();
    resi();
    return 0;
}