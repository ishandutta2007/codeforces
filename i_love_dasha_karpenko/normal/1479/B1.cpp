#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
const ll DIM = 1E5+7;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll prev[] = {0,0};
    ll res = 0;
    ll last = -1;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        if (last==-1){
            last = A[i];
            continue;
        }
        if (A[i]==last){
            if (prev[0]!=last)++res;
            if (prev[1]!=last)++res;
            prev[1] = prev[0] = last;
            last = -1;
            continue;
        }
        if (prev[0]==A[i]){
            prev[0] = last;
            ++res;
        }
        else if (prev[1]==A[i]){
            prev[1] = last;
            ++res;
        }
        else{
            if (prev[0]!=last){
                prev[0] = last;
                ++res;
            }
            else if (prev[1]!=last){
                prev[1] = last;
                ++res;
            }
        }
        last = A[i];
    }
    if (last!=-1)
        if (prev[0]!=last || prev[1]!=last)++res;
    cout<<res<<endl;
    return 0;
}