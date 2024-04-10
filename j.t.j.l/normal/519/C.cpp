#include<iostream>
#include<cmath> 
#include<cstring> 
#include<cstdio>
#include<algorithm>
#define N 120007
#define INF 2147483647
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,m,q;

int main(){
    cin>>n>>m;
    if (n>m){
        q=n;n=m;m=q;
    }
    if (2*n<=m)
        cout<<n<<endl;
    else
        cout<<(n+m)/3<<endl;
    return 0;
}