#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

int n,a0,a1,ans1,ans0,g,res;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    cin >> n >> s;

    for(int i=0; i<s.size(); i++)
        if(s[i]=='G')
            g++;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='G'){
            a0++;
            a1++;
            ans1=max(ans1,a1);
            ans0=max(ans0,a0);
        }
        if(s[i]=='S'){
            a1=a0;
            a0=0;
            ans1=max(ans1,a1);
            ans0=max(ans0,a0);
        }
    }

    res = ans0;
    if( ans1 < g )
        res=max(res,ans1+1);
    if( ans0 < g)
        res=max(res,ans0+1);
    if(ans1==g)
        res=max(res,ans1);

    cout << res << '\n';

    return 0;
}