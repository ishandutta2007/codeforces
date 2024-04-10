#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long long n,a,b,i;
    cin>>n>>a>>b;
    for(i=0;i*a<=n;i++){
        if((n-a*i)%b==0){
            cout<<"YES\n"<<i<<" "<<(n-a*i)/b;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}