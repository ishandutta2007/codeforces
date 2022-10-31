#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define INF 1000000007
typedef pair<long long,long long> pairll;
long long n,A[DIM],h,i;
vector<long long> V,S;
int main()
{
   // freopen("input.txt","r",stdin);
    scanf("%lld %lld\n",&n,&h);
    for (i = 1;i<=n;i++){
        scanf("%lld",&A[i]);
        if (A[i]>h)break;
        V.push_back(A[i]);
    }
    if (A[i]>h)i--;
    while(i>=1){
        S=V;
        long long res = 0;
        sort(S.begin(),S.end());
        for (int j = S.size()-1;j>=0;j-=2){
            res+=S[j];
            if (res>h)break;
        }
        if (res<=h){
            //cout<<S[S.size()-2]<<endl;
            printf("%lld\n",i-1);
            return 0;
        }
        i--;
        V.resize(V.size()-1);
    }

}