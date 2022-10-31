#include <bits/stdc++.h>

using namespace std;
#define DIM 200
long long n,A[DIM],o=1,cn=0,j;
set<long long,long long> S;
int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    cin>>n;
    o = n-1;
    for (int i = 1;i<=n;i++){cin>>A[i];}
    sort(A+1,A+n+1);
    if (A[n]==1){
        for (int i = 1;i<=2;i++)cout<<A[i]<<' ';
        return 0;
    }
    cout<<A[n]<<' ';
    for (int i = n-1;i>=1;i--){
        if (A[n]%A[i]!=0 || A[i]==1 || A[i]==A[i+1]){
            cout<<A[i]<<endl;
            return 0;
        }
    }
}