#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
long long n;
map<long long,long long> M;
vector<long long> V;
int main()
{
    cin>>n;
    for (int i = 1;i<=n;i++){
        long long x; cin>>x;
        if (M.count(x)==0){V.push_back(x);M[x]=1;}
        else M[x]++;
    }
    if (M.size()!=2 || M[V[0]]!=M[V[1]]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES\n"<<V[0]<<' '<<V[1]<<endl;
    }
}