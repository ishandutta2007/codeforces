#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pi;

int n, x[2005], y[2005];

vector<pi> v;

int ccw(pi a, pi b){
    int tmp = a.first * b.second - b.first * a.second;
    if(tmp > 0) return 1;
    if(tmp < 0) return -1;
    return 0;
}

bool cmp(pi a, pi b){
    return ccw(a,b) > 0;
}

int solve(int p){
    v.clear();
    int ret = 0;
    for (int i=p+1; i<n; i++) {
        v.push_back(pi(x[i] - x[p],y[i] - y[p]));
        if(v.back().first < 0){
            v.back().first = -v.back().first;
            v.back().second = -v.back().second;
        }
        if(v.back().first == 0 && v.back().second < 0){
            v.back().second = -v.back().second;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0; i<v.size();) {
        int e = i;
        while (e < v.size() && ccw(v[i],v[e]) == 0) {
            e++;
        }
        ret += (e - i) * (e - i - 1) / 2;
        i = e;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&x[i],&y[i]);
    }
    int ret = (n * (n-1) / 2);
    if(ret % 3){
        ret *= (n-2)/3;
    }
    else{
        ret /= 3;
        ret *= n-2;
    }
    for (int i=0; i<n; i++) {
        ret -= solve(i);
    }
    printf("%d",ret);
}