#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n,a[305];
char str[305][305];
int vis[305];
vector<int> v,l;

void dfs(int pos){
    if(vis[pos]) return;
    vis[pos] = 1;
    v.push_back(a[pos]);
    l.push_back(pos);
    for (int i=0; i<n; i++) {
        if(!vis[i] && str[pos][i] == '1') dfs(i);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    for (int i=0; i<n; i++) {
        if(vis[i]) continue;
        v.clear();
        l.clear();
        dfs(i);
        sort(v.begin(),v.end());
        sort(l.begin(),l.end());
        for (int i=0; i<l.size(); i++) {
            a[l[i]] = v[i];
        }
    }
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}