#include <iostream>
#include <algorithm>
using namespace std;

int c[200009], a[200009], m[200009], mn, mi;
bool vs[200009], f;

void dfs(int n)
{
    vs[n] = true;
    int tn = a[n];
    if (vs[tn] == true){
        if (m[tn] == 0){
            mn = c[n]; mi = tn;
            if (n != tn) f = true;
            return;
        }
        else{
            m[n] = m[tn];
            return;
        }
    }
    dfs(tn);
    if (f){
        mn = min(mn, c[n]);
        if (mi == n)
            f = false;
    }
    if (mn == -1)
        m[n] = m[tn];
}

void rdfs(int n, int c)
{
    m[n] = c;
    if (!m[a[n]]) rdfs(a[n], c);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++) cin>>c[i];
    for (int i = 1; i <= n; i++) cin>>a[i];
    int s = 0;
    for (int i = 1; i <= n; i++){
        if (vs[i]) continue;
        f = false; mn = mi = -1;
        dfs(i);
        if (mn != -1){
            rdfs(i, mn);
            s += mn;
        }
    }
    cout<<s<<'\n';
    return 0;
}