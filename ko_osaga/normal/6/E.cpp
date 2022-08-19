#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, d, a[100005];

deque<int> dmax, dmin;
deque<int> pmax, pmin;

int trial(int x){
    for (int i=1; i<=n; i++) {
        if(!pmax.empty() && pmax.front() == i - x){
            pmax.pop_front();
            dmax.pop_front();
        }
        if(!pmin.empty() && pmin.front() == i-x){
            pmin.pop_front();
            dmin.pop_front();
        }
        while (!dmax.empty() && dmax.back() < a[i]) {
            dmax.pop_back();
            pmax.pop_back();
        }
        dmax.push_back(a[i]);
        pmax.push_back(i);
        while (!dmin.empty() && dmin.back() > a[i]) {
            dmin.pop_back();
            pmin.pop_back();
        }
        dmin.push_back(a[i]);
        pmin.push_back(i);
        if(i >= x && dmax.front() - dmin.front() <= d){
            return 1;
        }
    }
    return 0;
}

vector<int> ret;
int main(){
    scanf("%d %d",&n,&d);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    int s = 0, e = n;
    while (s != e) {
        int m = (s+e+1)/2;
        if(trial(m)) s = m;
        else e = m-1;
        pmax.clear();
        dmax.clear();
        pmin.clear();
        dmin.clear();
    }
    printf("%d ",s);
    for (int i=1; i<=n; i++) {
        if(!pmax.empty() && pmax.front() == i -s){
            pmax.pop_front();
            dmax.pop_front();
        }
        if(!pmin.empty() && pmin.front() == i-s){
            pmin.pop_front();
            dmin.pop_front();
        }
        while (!dmax.empty() && dmax.back() < a[i]) {
            dmax.pop_back();
            pmax.pop_back();
        }
        dmax.push_back(a[i]);
        pmax.push_back(i);
        while (!dmin.empty() && dmin.back() > a[i]) {
            dmin.pop_back();
            pmin.pop_back();
        }
        dmin.push_back(a[i]);
        pmin.push_back(i);
        if(i >= s && dmax.front() - dmin.front() <= d){
            ret.push_back(i);
        }
    }
    printf("%d\n",(int)ret.size());
    for (int i=0; i<ret.size(); i++) {
        printf("%d %d\n",ret[i] - s +1,ret[i]);
    }
}