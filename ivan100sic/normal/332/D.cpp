#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct bignum{
    long long A[2000];
    int N;
    void reduce(){
        int i,j;
        N += 5;
        for (i=0; i<N; i++){
            A[i+1] += A[i] / 1000000;
            A[i] %= 1000000;
        }
        while (A[N]==0 && N>0) N--;
        N++;
    }
    void multiply(long long x){
        for (int i=0; i<N; i++) A[i] *= x;
        reduce();
    }
    void divide(long long x){
        for (int i=N-1; i>=1; i--){
            A[i-1] += 1000000*(A[i]%x);
            A[i] /= x;
        }
        A[0] /= x;
        reduce();
    }
    void set(long long x){
        A[0] = x;
        N=1;
        reduce();
    }
    bignum(){
        memset(A,0,sizeof(A));
        N = 1;
    }
    inline friend bignum operator +(bignum a,bignum b){
        bignum c;
        c.N = max(a.N,b.N);
        for (int i=0; i<c.N; i++) c.A[i] = a.A[i] + b.A[i];
        c.reduce();
        return c;
    }
    inline friend bool operator <(bignum a,bignum b){
        for (int i=1999; i>=0; i--){
            if (a.A[i] < b.A[i]) return true; else
            if (a.A[i] > b.A[i]) return false;
        }
        return false;
    }
    inline friend bool operator >(bignum a,bignum b){
        return b<a;
    }
    inline friend bool operator !=(bignum a,bignum b){
        return a<b || b<a;
    }
    inline friend bool operator ==(bignum a,bignum b){
        return !(a!=b);
    }
};

bignum Binom[2005];
bignum flysum,losum,bisum,nusum;

vector <int> Sus[2005];
int N,K;

int main(){
    int i,j,k;
    long long l,r,m,o;
    scanf("%d%d",&N,&K);
    for (i=1; i<N; i++){
        for (j=i+1; j<=N; j++){
            scanf("%d",&k);
            if (k!=-1){
                Sus[i].push_back(k);
                Sus[j].push_back(k);
            }
        }
    }
    Binom[K].set(1);

    for (i=K+1; i<=N; i++){
        Binom[i] = Binom[i-1];
        Binom[i].multiply(i);
        Binom[i].divide(i-K);
    }

    for (i=1; i<=N; i++){
        //printf("%d %d\n",i,Sus[i].size());
        nusum = Binom[Sus[i].size()];

        //printf("here");

        losum = losum + nusum;
        long long cs=0;
        for (j=0; j<Sus[i].size(); j++) cs += Sus[i][j];

        nusum.multiply(cs);
        nusum.multiply(K);

        nusum.divide(Sus[i].size());
        flysum = flysum + nusum;
    }
    //divide flysum with losum
    l=0;
    r=1000000000ll * N;
    o=-1;
    while (l<=r){
        m = (l+r)/2;
        nusum = losum;
        nusum.multiply(m);
        if ((nusum < flysum) || (nusum == flysum)){
            o = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    printf("%I64d\n",o);
    return 0;
}