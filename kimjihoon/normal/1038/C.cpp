#include <iostream>
#include <algorithm>
using namespace std;

int a[100009], b[100009];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>a[i];
    for (int i = 1; i <= n; i++) cin>>b[i];
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    long long as = 0, bs = 0;
    int ai = n, bi = n, t = 0;
    while (ai > 0 || bi > 0){
        if (!t){
            if (bi == 0 || (ai != 0 && a[ai] > b[bi])){as += a[ai]; ai--;}
            else bi--;
        }
        else{
            if (bi == 0 || (ai != 0 && a[ai] > b[bi])) ai--;
            else {bs += b[bi]; bi--;}
        }
        t = (t + 1) % 2;
    }
    cout<<as - bs<<'\n';
    return 0;
}