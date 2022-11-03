#include <bits/stdc++.h>

using namespace std;

int main(){
        long long n,k;
        cin>>n>>k;
        n=min(n,k-1);
        long long ans;
        if (n<=k/2) ans=0;
        else 
                ans=(k-1)/2-(k-n)+1;

        cout<<ans;
}