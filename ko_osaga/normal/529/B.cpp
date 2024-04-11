#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int psum[1005];

int main(){
    int n, w[1005], h[1005];
    scanf("%d",&n);
    int high = 0;
    for (int i=0; i<n; i++) {
        scanf("%d %d",&w[i],&h[i]);
        high = max(high,min(w[i],h[i]));
    }
    int sol =2e9;
    for (int i=high; i<=1000; i++) {
        int ret = 0;
        int cnt = n/2;
        vector<int> v;
        for (int j=0; j<n; j++) {
            if(h[j] > i){
                cnt--;
                ret += h[j];
            }
            else{
                if(w[j] <= i) v.push_back(h[j] - w[j]);
                ret += w[j];
            }
        }
        if(cnt < 0) continue;
        sort(v.begin(),v.end());
        int j = 0;
        while (cnt > 0 && j < v.size() && v[j] < 0) {
            cnt--;
            ret += v[j];
            j++;
        }
        sol = min(sol,i * ret);
    }
    printf("%d",sol);
}