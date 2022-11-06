#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+10;
const ll p=1e9+7;
ll a[1000010],b[N],c[N],d[N];
int m;
class Matrix {
public:
     long long a[N][N];
//
    Matrix(){}
    //
    void init(long long  num[N]){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                a[i][j] = num[(i-j+m)%m];
           }
       }
    }
    //

    friend Matrix operator*(Matrix &m1 ,Matrix &m2) {
        int i, j, k;
        Matrix temp;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                temp.a[i][j] = 0;
                for(k = 0 ; k < m ; k++)
                   temp.a[i][j] += (m1.a[i][k] * m2.a[k][j])%p;
                temp.a[i][j] %= p;
//
           }
        }
        return temp;
    }
    //

    friend Matrix quickpow(Matrix &M ,int n){
        Matrix tempans;
//
        //
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == j)
                    tempans.a[i][j] = 1;
                else
                    tempans.a[i][j] = 0;
            }
        }
        //
        while(n){
            if(n & 1)
                tempans = tempans * M;
//*
            n = n >> 1;
            M = M * M;
        }
       return tempans;
    }
};
Matrix A;
int main()
{
    int n,l,i,j;
    cin>>n>>l>>m;
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==m)x=0;
        c[x]++;
    }
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==m)x=0;
        a[i]=x;
        b[x]++;
    }
    for(i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==m)x=0;
        d[(x+a[i])%m]++;
    }
    A.init(b);
    A=quickpow(A,l-2);
    ll ans=0;
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            //if((c[i]*d[j]*A.a[(2*m-i-j)%m][0])%p!=0)cout<<i<<' '<<j<<' '<<(2*m-i-j)%m<<' '<<(c[i]*d[j]*A.a[(2*m-i-j)%m][0])%p<<endl;
            ans+=((c[i]*d[j]%p)*A.a[(2*m-i-j)%m][0])%p;
        }
    ans%=p;
    cout<<ans;
    return 0;
}