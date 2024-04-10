#include <bits/stdc++.h>

using namespace std;
//#define DIM 30007
#define DIM 200007
#define INF 1000000000000000007
#define MAXN 1000007
typedef pair<long long, long long > pairll;
long long n,t,res = 0,Res[DIM],len = 450,A[DIM],M[MAXN];



struct troinik {
    long long l,r,num;
};



bool mycompare(troinik a,troinik b){
    if (a.l/len==b.l/len)return a.r<b.r;
    return a.l/len<b.l/len;
}
void delit(long long x){

    res-=A[x]*(2*M[A[x]]-1);
    M[A[x]]--;
}

void addit(long long x){
    M[A[x]]++;
    res+=A[x]*(2*M[A[x]]-1);

}
troinik Q[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%I64d %I64d\n",&n,&t);
    for (int i = 1;i<=n;i++)scanf("%I64d",&A[i]);
    for (int i = 1;i<=t;i++){
        scanf("%I64d %I64d\n",&Q[i].l,&Q[i].r);
        Q[i].num = i;
    }
    sort(Q+1,Q+1+t,mycompare);
    long long L=1,R=0;
    for (int i = 1;i<=t;i++){
        while(L<Q[i].l)delit(L++);
        while(L>Q[i].l)addit(--L);
        while(R>Q[i].r)delit(R--);
        while(R<Q[i].r)addit(++R);
        Res[Q[i].num]=res;
    }
    for (int i = 1;i<=t;i++){
        printf("%I64d\n",Res[i]);
    }
}