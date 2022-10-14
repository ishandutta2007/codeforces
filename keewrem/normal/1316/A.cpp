#include <bits/stdc++.h>
using namespace std;
long long t,n,m,a,k;
int main(){
    cin >> t;
    while(t--){
        k = 0;
        cin >> n>>m;
        while(n--){
            scanf("%d",&a);
            k+=a;
        }
        cout << min(m,k)<<"\n";
    }
    return 0;
}