#include <bits/stdc++.h>

using namespace std;
#define DIM 57
#define INF 100000007
typedef long long ll;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,m;
arr A[DIM],B[DIM];
int main()
{
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++)cin>>A[i][j];
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++)cin>>B[i][j];
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            if (A[i][j]>B[i][j])swap(A[i][j],B[i][j]);
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            if ( !(A[i][j]>A[i][j-1] && A[i][j]>A[i-1][j]) ){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            if ( !(B[i][j]>B[i][j-1] && B[i][j]>B[i-1][j]) ){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}