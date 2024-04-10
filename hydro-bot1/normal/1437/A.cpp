// Hydro submission #618e10f2df417b8c5f5bfba3@1636700408669
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,a,b;
int main() {
    scanf("%d",&_);
    while(_--){
        scanf("%d%d",&a,&b);
        int s=b+1;
        if(a>=(s+1)/2)puts("YES");
        else puts("NO");
    }
    return 0;
}