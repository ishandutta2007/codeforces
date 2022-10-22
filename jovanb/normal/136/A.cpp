#include <iostream>

using namespace std;
int niz[10000];
int daje[10000];
int main() {
    int n,x,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x;
        daje[x]=i;
    }
    for(i=1;i<=n;i++)cout<<daje[i]<<" ";
    return 0;
}