#include <bits/stdc++.h>

using namespace std;
#define DIM2 507
#define DIM 200007

#define INF 10E18
#define MAXN 10007
typedef pair<long long,long long> pairll;
struct troinik{
    long long b,w,t;
};
long long n,A[DIM],res = -INF,mx=-INF;
int main() {
    //freopen("input.txt","r",stdin);
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>A[i];
        mx = max(mx,A[i]);
    }
    long long cres = 0,last;
    for (int i = n;i>=n;i--){
        cres = A[i];
        last = A[i];
        for (int j = i-1;j>=1;j--){
            if (last==0)break;
            if (A[j]>=last){cres+=last-1;last--;}
            else{
                last = A[j];
                cres+=last;
            }
        }
        res = max(res,cres);
        //cout<<cres<<endl;
        if (A[i]==mx)break;
    }
    cout<<res<<endl;
}