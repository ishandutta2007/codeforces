//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 1e5+7;
int A[N],B[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
      //  A[i] = rand()%int(5e5);
      cin>>A[i];
    }
    sort(A+1,A+1+n);
    int iter = 0;
    int zer = 0;
    while(n>1){
        ++iter;
        int ptr = 0;

        if (zer>0){
            B[++ptr] = A[1];
            zer -= 1;
        }

        for(int i = 2;i<=n;i+=1){
            if (A[i]-A[i-1]>0){
                B[++ptr] = A[i]-A[i-1];
            }
            else{
                zer += 1;
            }
        }
        sort(B+1,B+1+ptr);
        for(int i = 1;i<=ptr;i+=1){
            A[i] = B[i];
        }
        n = ptr;
    }
    //cout<<iter<<endl;
    if (n==0){
        cout<<"0\n";
    }
    else{
        cout<<A[1]<<endl;
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}