#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
long long i,j,k,n,m,a[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        long long sum=0,w=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&k);
            sum=max(sum,k|m);
        }
        cout<<sum<<endl;
    }
}