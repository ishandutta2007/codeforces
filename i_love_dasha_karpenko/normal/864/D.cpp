#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
long long n,A[DIM],res=0;
pair<long long,long long> B[DIM];
set<long long> S,S1,SC;
map<long long,long long> M;
vector<long long> V;
int main()
{
    cin>>n;
    for (int i = 1;i<=n;i++)S.insert(i);
    for (int i = 1;i<=n;i++){
        long long x; cin>>A[i];
        S.erase(A[i]);

        //S1.insert(A[i]);
        if (M.count(A[i])==0)M[A[i]]=0;
        M[A[i]]++;
    }
   for (int i = 1;i<=n;i++){
        if (M[A[i]]>=2 || A[i]>n || A[i]<1)V.push_back(i);
   }
   for (int j = 0;j<V.size();j++){
        int i = V[j];

    auto it = S.begin();
        if (M[A[i]]>=2 && S1.count(A[i])==0 && A[i]<*it){M[A[i]]--; S1.insert(A[i]);continue;}
        if (M[A[i]]==1 && A[i]<=n && A[1]>=1 && S1.count(A[i])==0)continue;
        else{
            M[A[i]]--;
            A[i]=*it;
            S1.insert(A[i]);
            S.erase(*it);
            res++;
        }
   }
    cout<<res<<endl;

    for (int i = 1;i<=n;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}