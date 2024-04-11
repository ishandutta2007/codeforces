#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef long long lint;
typedef pair<int,int> pi;

int n;
char t[100005];
int l[100005], r[100005], q;
int qnum[100005];

priority_queue<pi,vector<pi>,greater<pi> > pq;

int main(){
    scanf("%s",t);
    for (int i=0; t[i]; i++){
        if(t[i] == '?') qnum[i] = q++;
    }
    for (int i=0; i<q; i++) {
        scanf("%d %d",&l[i],&r[i]);
    }
    int hi = 0;
    lint res = 0;
    for (int i=0; t[i]; i++) {
        if(t[i] == '(') hi++;
        else if(t[i] == ')') hi--;
        else{
            t[i] = ')';
            pq.push(pi(l[qnum[i]] - r[qnum[i]],i));
            hi--;
            res += r[qnum[i]];
        }
        if(hi < 0){
            if(pq.empty()){
                puts("-1");return 0;
            }
            pi x = pq.top();
            pq.pop();
            t[x.second] = '(';
            hi += 2;
            res += x.first;
        }
    }
    if(hi != 0) puts("-1");
    else printf("%I64d\n%s",res,t);
}