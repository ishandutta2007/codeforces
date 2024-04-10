#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10000000007
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll n,last = -DIM,all=1;
arr A;
char F[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>A[i];
    }
    ll i = 1,j = n,num;
    char Q;
    while(i<=j){
        if (A[i]>last && A[j]>last){
            if (A[i]<A[j]){
                num = A[i];
                i++;
                Q = 'L';
            }
            else{
                num = A[j];
                j--;
                Q = 'R';
            }
        }
        else{
            if (A[i]>last){

                num = A[i];
                i++;
                Q = 'L';
            }
            else if (A[j]>last){
                num = A[j];
                j--;
                Q = 'R';
            }
            else{
                break;
            }
        }
        last = num;
        F[all++]=Q;
    }
    cout<<all-1<<endl;
    for (int i = 1;i<all;i++){
        cout<<F[i];
    }
}