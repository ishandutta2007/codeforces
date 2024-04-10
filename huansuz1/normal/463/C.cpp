#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;
long long a[2345][2345],b[2345][2345],c[2345][2345],d[2345][2345],e[2345][2345];
int n;
ll ma,xx,yy,xxx,yyy,mi;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            scanf("%d",&c[i][j]); 
            a[i][j]=c[i][j];
            b[i][j]=c[i][j];
        } 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j]+=a[i-1][j-1];
            b[i][j]+=b[i-1][j+1];
        }
    }   
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int p=n-max(i,j);
            a[i][j]=a[i+p][j+p];
            if (i==1 || j==n && i!=n) b[i][j]=b[j][i]; else
                if (i!=n && j!=1 && i!=1 && j!=n) {
                    b[i][j]=b[i-1][j+1];
                }   
        }
    }
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) 
            if ((i+j)%2==0) {
                if (max(a[i][j]+b[i+1][j-1]-c[i][j],a[i][j]+b[i-1][j+1]-c[i][j])>=ma) {ma=max(a[i][j]+b[i+1][j-1]-c[i][j],a[i][j]+b[i-1][j+1]-c[i][j]); xx=i; yy=j;} 
            } else {
                if (max(a[i][j]+b[i+1][j-1]-c[i][j],a[i][j]+b[i-1][j+1]-c[i][j])>=mi) {mi=max(a[i][j]+b[i+1][j-1]-c[i][j],a[i][j]+b[i-1][j+1]-c[i][j]); xxx=i; yyy=j;}
            }

    cout<<ma+mi<<endl;
    cout<<xx<<" "<<yy<<" "<<xxx<<" "<<yyy;
    
    


    return 0;
}