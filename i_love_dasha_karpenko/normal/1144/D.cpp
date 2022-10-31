#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 1000000000000000007
long long n,mx=0,A[DIM],num;
map<long long,long long> M;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
        //cout<<A[i]<<' ';
        if (M.count(A[i])==0)M[A[i]]=1;
        else M[A[i]]++;
        if (M[A[i]]>mx){
            mx = M[A[i]];
            num = A[i];
        }
    }
    printf("%lld\n",n-mx);
    int flag = 0;
    int i = 1;
    while(A[i]!=num)i++;
    int j = i-1;
    int ind;
    while(j>=1){

        if (A[j]>num)ind = 2;
        else ind = 1;
        printf("%d %d %d\n",ind,j,j+1);
        j--;
    }
    j=i+1;
    while(j<=n){
        if (A[j]>num)ind = 2;
        else ind = 1;
        if (A[j]!=num)printf("%d %d %d\n",ind,j,j-1);
        j++;
    }
}