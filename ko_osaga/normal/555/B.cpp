#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long lint;
typedef pair<lint,lint> pi;

struct seg{
    lint s,e;
    int x;
};

vector<seg> v;
multimap<lint,lint> mp;
// mp[endpoint] -> segment number;

bool cmp(seg a,seg b){return a.s < b.s;}

int n, m;
pi arr[200005];
pi tmp[200005];

int match[200005];

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%lld %lld",&arr[i].first,&arr[i].second);
        if(i >= 2){
            v.push_back({arr[i].first - arr[i-1].second,arr[i].second - arr[i-1].first,i-1});
        }
    }
    for (int i=0; i<m; i++) {
        scanf("%lld",&tmp[i].first);
        tmp[i].second = i+1;
    }
    sort(tmp,tmp+m);
    sort(v.begin(),v.end(),cmp);
    int pt = 0;
    for (int i=0; i<m; i++) {
        while (pt < v.size() && v[pt].s <= tmp[i].first) {
            mp.insert(pi(v[pt].e,v[pt].x));
            pt++;
        }
        auto t = mp.lower_bound(tmp[i].first);
        if(t == mp.end()){
            continue;
        }
        match[t->second] = (int)tmp[i].second;
        mp.erase(t);
    }
    for(int i=1; i<n;i++){
        if(match[i] == 0){
            puts("No");return 0;
        }
    }
    puts("Yes");
    for (int i=1; i<n; i++) {
        printf("%d ",match[i]);
    }
}