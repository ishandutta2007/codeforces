#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int A[100005],N,M,i,j,k,l,r,m,o;
long long sol0,sol,solq;

vector <int> P[100005];

int aps(int x){
    if (x<0) return -x;
    return x;
}

int Me[200005],MC;

void median_add(int x){
    Me[++MC] = x;
}

int median_find(){
    sort(Me+1,Me+MC+1);
    return Me[MC/2+1];
}

int main(){
    scanf("%d%d",&M,&N);
    j = 0;
    for (i=1; i<=N; i++){
        scanf("%d",&k);
        if (k != A[j]){
            j++;
            A[j] = k;
        }
    }
    N = j;
    for (i=1; i<=N; i++){
        P[A[i]].push_back(i);
    }
    for (i=1; i<N; i++){
        sol0 += aps(A[i]-A[i+1]);
    }
    sol = sol0;
    for (i=1; i<=M; i++){
        k = P[i].size();
        if (k==0) continue;
        MC = 0;
        solq = sol0;
        for (j=0; j<k; j++){
            l = P[i][j];
            if (l>1) median_add(A[l-1]);
            if (l<N) median_add(A[l+1]);
        }
        m = median_find();
        for (j=1; j<=MC; j++){
            solq += aps(m - Me[j]) - aps(i - Me[j]);
        }
        if (solq < sol) sol = solq;
    }
    printf("%lld\n",sol);
    return 0;
}