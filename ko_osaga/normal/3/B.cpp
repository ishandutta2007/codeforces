#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;

int n, v;
vector<pi> v1, v2;
vector<lint> ps1, ps2;

int main(){
    scanf("%d %d",&n,&v);
    for (int i=1; i<=n; i++) {
        int t, p;
        scanf("%d %d",&t,&p);
        if(t == 1){
            v1.push_back(pi(p,i));
        }
        else{
            v2.push_back(pi(p,i));
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    v1.push_back(pi(0,0));
    v2.push_back(pi(0,0));
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    for (int i=0; i<v1.size(); i++) {
        if(i == 0) ps1.push_back(0);
        else ps1.push_back(v1[i].first + ps1.back());
    }
    for (int i=0; i<v2.size(); i++) {
        if(i == 0) ps2.push_back(0);
        else ps2.push_back(v2[i].first + ps2.back());
    }
    lint ret = 0;
    int pos = 0;
    for (int i=0; i<v2.size(); i++) {
        int onecnt = v - 2 * i;
        onecnt = min(onecnt,(int)v1.size() - 1);
        if(onecnt < 0) break;
        if(ps2[i] + ps1[onecnt] > ret){
            ret = ps2[i] + ps1[onecnt];
            pos = i;
        }
    }
    printf("%I64d",ret);
    for (int i=1; i<=min(v - 2 * pos,(int)v1.size()-1); i++) {
        printf("\n%d",v1[i].second);
    }
    for (int i=1; i<=pos; i++) {
        printf("\n%d",v2[i].second);
    }
}