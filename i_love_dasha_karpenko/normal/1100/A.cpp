#include <bits/stdc++.h>

using namespace std;
#define DIM 107
#define INF 1000000000007
typedef pair<long long, long long> pairll;
long long n,k,A[DIM],F[DIM],mx=0;
int main() {

	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	cin>>n>>k;
	for (int i = 1;i<=n;i++)cin>>A[i];
	for (int i = 1;i<=k;i++){
        long long cy=0,cn=0;
        for (int j = 1;j<=n;j++){
            if ((j-i)%k!=0){
                if (A[j]==-1)cy++;
                else cn++;
            }
        }
        if (abs(cy-cn)>mx)mx=abs(cy-cn);
	}
	cout<<mx<<endl;
}