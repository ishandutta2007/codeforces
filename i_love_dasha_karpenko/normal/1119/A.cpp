#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define INF 1000000007
typedef pair<long long,long long> pairll;
long long n,dist =0;
map<long long,pairll> M;
vector<pairll> A,B;
bool mycompare(pairll a,pairll b){return a.first>b.first;}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%I64d\n",&n);
    for (int i = 1;i<=n;i++){
        long long x;
        scanf("%I64d",&x);
        if (M.count(x)==1){
            M[x].second = i;
        }
        else{
            M[x]={i,i};
        }
    }
    long long res;
    int i = 0;
    for (auto it = M.begin();it!=M.end();it++){
        i++;
        pairll k = (*it).second;
        A.push_back({k.first,i});
        B.push_back({k.second,i});
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    n = A.size()-1;
    for (int i = 0;i<A.size();i++){
        if (B[n].first-A[i].first<=dist)break;
        if (B[n].second==A[i].second){
            dist = max(dist,B[n-1].first-A[i].first);
        }
        else{

            dist = max(dist,B[n].first-A[i].first);
            break;
        }
    }
    printf("%I64d\n",dist);

    //sadasd
}