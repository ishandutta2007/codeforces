#include <bits/stdc++.h>

using namespace std;
#define DIM 10007
long long n,p1 = 96,p2 = 96+27,res = 0;
set<char> M;
int main()
{
    cin>>n;
    long long cres = 0;
    for (int i = 1;i<=n;i++){
        char x; cin>>x;
        if (p1<x && x<p2)M.insert(x);
        else M.clear();
        res = max(res,(long long)(M.size()));

    }


    cout<<res<<endl;
}