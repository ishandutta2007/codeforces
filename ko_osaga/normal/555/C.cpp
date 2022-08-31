#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> pi;

vector<int> vx, vy;
int n, q;
int x[200005], y[200005], qry[200005];


set<pi> sl, su;

void input(){
    scanf("%d %d",&n,&q);
    for (int i=0; i<q; i++) {
        char str[5];
        scanf("%d %d %s",&x[i],&y[i],str);
        if(str[0] == 'U') qry[i] = 1;
        else qry[i] = 2;
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    vx.push_back(0);
    vy.push_back(0);
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for (int i=0; i<q; i++) {
        x[i] = (int)(lower_bound(vx.begin(),vx.end(),x[i]) - vx.begin());
        y[i] = (int)(lower_bound(vy.begin(),vy.end(),y[i]) - vy.begin());
        if(qry[i] == 2 && sl.find(pi(x[i],y[i])) != sl.end()){
            x[i] = -1;
            y[i] = -1;
        }
        else{
            sl.insert(pi(x[i],y[i]));
        };
        if(qry[i] == 1 && su.find(pi(x[i],y[i])) != su.end()){
            x[i] = -1;
            y[i] = -1;
        }
        else{
            su.insert(pi(x[i],y[i]));
        }
    }
}

struct seg{
    int tree[530000];
    void lazydown(int p){
        tree[2*p] = max(tree[2*p],tree[p]);
        tree[2*p+1] = max(tree[2*p+1],tree[p]);
        return;
    }
    void add(int s, int e, int ps, int pe, int p, int v){
        if(e < ps || pe < s) return;
        if(s <= ps && pe <= e){
            tree[p] = max(tree[p],v);
            return;
        }
        lazydown(p);
        int pm = (ps + pe) / 2;
        add(s,e,ps,pm,2*p,v);
        add(s,e,pm+1,pe,2*p+1,v);
    }
    int q(int pos, int ps, int pe, int p){
        if(ps == pe) return tree[p];
        lazydown(p);
        int pm = (ps + pe) / 2;
        if(pos <= pm) return q(pos,ps,pm,2*p);
        return q(pos,pm+1,pe,2*p+1);
    }
}rmqu, rmql;

int main(){
    input();
    for (int i=0; i<q; i++) {
        if(x[i] == -1){
            puts("0");
            continue;
        }
        if(qry[i] == 1){
            int piv = rmqu.q(x[i],1,(int)vx.size(),1);
            printf("%d\n",vy[y[i]] - vy[piv]);
            rmql.add(piv+1,y[i],1,(int)vy.size(),1,x[i]);
        }
        else{
            int piv = rmql.q(y[i],1,(int)vy.size(),1);
            printf("%d\n",vx[x[i]] - vx[piv]);
            rmqu.add(piv+1,x[i],1,(int)vx.size(),1,y[i]);
        }
    }
}