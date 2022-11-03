#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 200001;

int main()
{
    int n;
    cin >> n;
    int a,cur,mx=1,val=1;
    cin >> a;
    cur = a;
    for(int i=1;i<n;i++){
        cin >> a;
        if(a>cur){
            val++;
            mx = max(mx,val);
        }else{
            val = 1;
        }
        cur = a;
    }
    cout << mx;
}