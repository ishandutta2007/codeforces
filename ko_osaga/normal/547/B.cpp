#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pi;
map<int,int> mp;

struct disj{
    int pa[200005], size[200005];
    void insert_one(int x){
        size[x] = 1;
        pa[x] = x;
    }
    int find(int x){
        return pa[x] = (pa[x] == x ? x : find(pa[x]));
    }
    int uni(int x, int y){
        x = find(x);
        y = find(y);
        if(size[x] == 0 || size[y] == 0) return 0;
        if(x == y) return size[x];
        pa[x] = y;
        size[y] += size[x];
        return size[y];
    }
}disj;

int n, a[200005];

pi b[200005];
int maxval[200005];

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        b[i-1] = pi(a[i],i);
    }
    sort(b,b+n);
    reverse(b,b+n);
    for (int i=0; i<n; i++) {
        disj.insert_one(b[i].second);
        disj.uni(b[i].second,b[i].second-1);
        disj.uni(b[i].second,b[i].second+1);
        int pos =disj.size[disj.find(b[i].second)];
        maxval[pos] = max(maxval[pos],b[i].first);
    }
    for (int i=n; i>=0; i--) {
        maxval[i]= max(maxval[i],maxval[i+1]);
    }
    for (int i=1; i<=n; i++) {
        printf("%d ",maxval[i]);
    }
}