/*
god taekyu
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int ans = 0;
    ans += abs(x1-x2)+1;
    if(x1==x2) {
        ans++;
    }
    ans += abs(y1-y2)+1;
    if(y1==y2) {
        ans++;
    }
    cout<<2*ans;
    return 0;
}

/*
god taekyu
*/