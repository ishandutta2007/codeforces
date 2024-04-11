#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lint;
typedef pair<lint,lint> pi;

int a[100005], n;
vector<int> graph[100005];

lint g(lint x, lint y){return y ? g(y,x%y) : x;}

bool valid(lint x, lint y){
    lint ret = 0;
    while (x) {
        ret += (x & 1) * y;
        x >>= 1;
        y <<= 1;
        if(ret > 1e14) return 0;
    }
    return 1;
}

pi f(int x, int pa){
    vector<pi> v;
    for (int i=0; i<graph[x].size(); i++) {
        if(graph[x][i] == pa)continue;
        v.push_back(f(graph[x][i],x));
    }
    if(v.empty()) return pi(1,a[x]);
    
    lint lcm = 1;
    for (int i=0; i<v.size(); i++) {
        if(valid(lcm,v[i].first / g(lcm,v[i].first))){
            lcm *= v[i].first / g(lcm,v[i].first);
        }
        else{
            lcm = 1e18;
            break;
        }
    }

    lint sec = 1e18;
    for (int i=0; i<v.size(); i++) {
        sec = min(sec,v[i].second / lcm);
    }
    return pi(lcm * v.size(), sec * lcm * v.size());
}

int main(){
    scanf("%d",&n);
    lint ret = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        ret += a[i];
    }
    for (int i=0; i<n-1; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    printf("%I64d",ret - f(1,0).second);
}