#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int v1,v2,v3,vm,i,j,k;
    cin>>v1>>v2>>v3>>vm;
    for(i=max(vm*2+1,v1);i<=v1*2;i++){
        for(j=max(v2,vm*2+1);j<=v2*2;j++){
            for(k=max(v3,vm);k<=min(v3*2,vm*2);k++){
                if(i>j && j>k){
                cout<<i<<endl<<j<<endl<<k<<endl;
                return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}