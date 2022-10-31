#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 1000000000000000007
long long k,res1 = 0,res2 = 0,res,cres = 0,F[DIM];
int A[DIM],B[DIM],C[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&k);
    char x;

    for (int i = 1;i<=k;i++){
        scanf("%c",&x);
        A[i]=x-97;
        //cout<<int(x)-97<<' ';
    }
    //cout<<endl;
    scanf("\n");
    for (int i = 1;i<=k;i++){
        scanf("%c",&x);
        B[i]=x-97;
        //cout<<int(x)-97<<' ';
    }
    //cout<<endl;
    for (int i = k;i>=1;i--){
        C[i]+=A[i]+B[i];
        C[i-1]+=C[i]/26;
        C[i]%=26;
    }
    //cout<<C[0]<<endl;
    //  cout<<endl;
    C[1]+=C[0]*26;
    for (int i = 1;i<=k;i++){
        C[i+1]+=C[i]%2*26;
        C[i]/=2;
        //cout<<C[i]<<endl;
    }
    for (int i = 1;i<=k;i++){
        cout<<char(C[i]+97);
    }
}