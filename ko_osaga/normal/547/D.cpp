#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pos{
    int x, y, num;
};

bool cmp1(pos a, pos b){
    return a.x != b.x ? (a.x < b.x) : (a.y < b.y);
}

bool cmp2(pos a, pos b){
    return a.y != b.y ? (a.y < b.y) : (a.x < b.x);
}

int n;
pos a[200005];
vector<int> graph[200005];
queue<int> q;

char str[200005];

void bfs(int x){
    q.push(x);
    str[x] = 'b';
    while (!q.empty()) {
        int qf = q.front();
        q.pop();
        for (auto &i : graph[qf]){
            if(str[i]) continue;
            str[i] = 'b' + 'r' - str[qf];
            q.push(i);
        }
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].num = i;
    }
    sort(a,a+n,cmp1);
    for (int i=0; i<n; ) {
        int e = i;
        while (e < n && a[e].x == a[i].x) {
            e++;
        }
        for (int j=i; j<e-1; j+=2) {
            graph[a[j].num].push_back(a[j+1].num);
            graph[a[j+1].num].push_back(a[j].num);
        }
        i = e;
    }
    sort(a,a+n,cmp2);
    for (int i=0; i<n; ) {
        int e = i;
        while (e < n && a[e].y == a[i].y) {
            e++;
        }
        for (int j=i; j<e-1; j+=2) {
            graph[a[j].num].push_back(a[j+1].num);
            graph[a[j+1].num].push_back(a[j].num);
        }
        i = e;
    }
    for (int i=0; i<n; i++) {
        if(!str[i]) bfs(i);
    }
    puts(str);
}