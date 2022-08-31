#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

struct seg{
    int pos, s, e, buho, obj;
};

int query[100005];

struct bit{
    int tree[1000050], lim;
    void init(int n){
        lim = n+2;
    }
    void add(int x, int v){
        x += 2;
        while(x <= lim){
            tree[x] += v;
            x += x & -x;
        }
    }
    int sum(int x){
        x += 2;
        int ret = 0;
        while(x){
            ret += tree[x];
            x -= x & -x;
        }
        return ret;
    }
    int sum_range(int s, int e){
        return sum(e) - sum(s-1);
    }
}bit;

bool cmp(seg a, seg b){return a.pos < b.pos;}

vector<seg> st;
vector<pi> pt;

vector<int> low, high;
stack<int> s;

char str[1000005];

int main(){
    scanf("%s",str);
    for (int i=0; str[i]; i++) {
        if(str[i] == '(') s.push(i+1);
        else if(!s.empty()){
            pt.push_back(pi(s.top(),i+1));
            s.pop();
        }
    }
    bit.init((int)strlen(str)+3);
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        int s,e;
        scanf("%d %d",&s,&e);
        st.push_back((seg){s-1,s,e,-1,i});
        st.push_back((seg){e,s,e,1,i});
    }
    sort(pt.begin(),pt.end());
    sort(st.begin(),st.end(),cmp);
    int p1 = 0, p2 = 0;
    while (p2 < pt.size() && pt[p2].first <= 0) {
        p2++;
    }
    while (p1 < st.size() && st[p1].pos <= 0) {
        p1++;
    }
    for (int i=0; str[i]; i++) {
        while (p2 < pt.size() && pt[p2].first == i+1) {
            bit.add(pt[p2].second,1);
            p2++;
        }
        while (p1 < st.size() && st[p1].pos == i+1) {
            query[st[p1].obj] += st[p1].buho * bit.sum_range(st[p1].s,st[p1].e);
            p1++;
        }
    }
    for (int i=0; i<q; i++) {
        printf("%d\n",query[i]*2);
    }
}