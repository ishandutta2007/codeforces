// gongy's code with lld
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

long long anum,bnum,temp,curd,cura,curb,mxa,mxb,s;
struct extra{
    long long first;long long second; long long dist;
    bool operator<(const extra & bunnies)const{
        return dist>bunnies.dist;
    }
};

extra curx, shot[400005];

priority_queue<extra> q;

FILE* fin;
FILE* fout;

int main(){
    //freopen("cfin.txt" ,"r", stdin);
    scanf("%lld ", &anum);
    for (int i=0;i<anum;i++){
        scanf("%lld ", &temp);
        shot[i].first=true;shot[i].dist=temp;
    }
    scanf("%lld ", &bnum);
    for (int i=anum;i<bnum+anum;i++){
        scanf("%lld ", &temp);
        shot[i].second=true;shot[i].dist=temp;
    }
    curx.dist=shot[0].dist;
    //make queue
    sort(shot, shot+anum+bnum);
    for (int i=0;i<bnum+anum;i++){
        if (shot[i].dist==curx.dist){
            shot[i].first == true ? curx.first++:curx.second++;
        } else if (shot[i].dist!=curx.dist){
            //new era
            q.push(curx);curx.first=0;curx.second=0;curx.dist=shot[i].dist;
            shot[i].first == true ? curx.first++:curx.second++;
        }
    }
    q.push(curx);s=q.size();
    //made queue
    //curd is the max distance for a 2 we are testing
    //first we test the smalles distance
    mxa=anum*3;mxb=bnum*3;
    cura = anum*3; curb = bnum*3;
    for (int i=0;i<s;i++){
        curx=q.top();q.pop();
        cura-=curx.first;curb-=curx.second;
        if (cura-curb>mxa-mxb){
            mxa=cura;mxb=curb;
        } else if (cura-curb==mxa-mxb){
            if (mxa<cura){
                mxa=cura;mxb=curb;
            }
        }
    }
    printf("%lld:%lld", mxa, mxb);
    return 0;
}