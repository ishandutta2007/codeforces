#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N,K;
ll a,b,c,d;
ll aa,bb,cc,dd,ee,ff;
int main(){
    cin >> T;
    while(T--){
        cin >> a>> b >> c >> d;
        cin >> aa >> bb >> cc >> dd >> ee >> ff;
        bool k = 1;
        if(!(cc <= aa && aa <= ee && dd <= bb && bb <= ff))k = 0;
        if(a+b>0 && cc == ee) k = 0;
        if(c+d>0 && dd == ff) k = 0;
        if(aa + b - a < cc || aa + b -a > ee) k = 0;
        if(bb + d - c < dd || bb + d - c > ff) k = 0;
        if(k)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}