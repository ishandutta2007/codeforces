#include<bits/stdc++.h>
#define lg2(x) 31 - __builtin_clz(x)
#define maxn 1001
#define ll long long
#define ull unsigned long long
#define ld long double
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);
    string s;
    int n;

    cin >>n >> s;
    bool b=0;
    for(int i=0; i<n; i++){
        if(b==0&&s[i]>s[i+1]){
            b=1;
        }
        else
            cout<<s[i];
    }

    return 0;
}