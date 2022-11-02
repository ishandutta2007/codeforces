#include <iostream>
using namespace std;
int p[200009], m[200009];
int main()
{
    int n, k, q, l, r, c = 0, a, b;
    cin>>n>>k>>q;
    for (int i = 1; i <= n; i++){
        cin>>l>>r;
        p[l]++; p[r+1]--;
    }
    for (int i = 1; i <= 200000; i++){
        c += p[i];
        if (c >= k)
            m[i] = m[i-1] + 1;
        else
            m[i] = m[i-1];
    }
    for (int i = 1; i <= q; i++){
        cin>>a>>b;
        cout<<m[b] - m[a-1]<<endl;
    }
    return 0;
}