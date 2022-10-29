#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int n;
    vector<int> ans;
    int tmp = gcd(a, b);
    for(int i=1;i*i<=tmp;i++){
        if(tmp%i==0) {
            ans.push_back(i);
            ans.push_back(tmp/i);
        }
    }
    sort(ans.begin(), ans.end());
    scanf("%d", &n);
    while(n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        auto x = upper_bound(ans.begin(), ans.end(), b)-ans.begin()-1;
        if(x < 0||ans[x]<a) printf("-1\n");
        else printf("%d\n", ans[x]);
    }
}