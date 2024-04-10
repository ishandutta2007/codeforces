#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define SZ 1048576
using namespace std;
int n, m, Res[101000];
map<int,int>MM;
struct point{
    int x, y, num;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}A[101000], B[101000];
struct AA{
    int b, e, d;
};
struct UU{
    int x, y, c;
    bool operator <(const UU &p)const{
        return x<p.x;
    }
};
vector<UU>U;
vector<AA>V;
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d%d",&A[i].x,&A[i].y);
    }
    A[n+1]={0,0};
    n++;
    sort(A+1,A+n+1);
    set<int>Set;
    int py = 0;
    A[n+1].x = 2e9;
    for(i=1;i<=n;i++){
        V.push_back({A[i].x,A[i].x, A[i].y-A[i].x});
        Set.insert(A[i].y);
        while(!Set.empty() && py > *Set.begin())Set.erase(Set.begin());
        while(!Set.empty() && py == *Set.begin()){
            Set.erase(Set.begin());
            py++;
        }
        if(A[i].x!=A[i-1].x && py < A[i].y){
            V.push_back({A[i].x,A[i].x,py - A[i].x});
            py++;
        }
        if(A[i].x +1 < A[i+1].x){
            int d = A[i+1].x - A[i].x - 1;
            int cur = A[i].x + 1;
            while(!Set.empty() && d){
                int b = *Set.begin();
                if(b <= py){
                    Set.erase(Set.begin());
                    if(py==b)py++;
                    continue;
                }
                int c = min(b - py, d);
                V.push_back({cur, cur + c-1, py-cur});
                cur += c;
                d -= c;
                py += c;
            }
            if(d>0){
                V.push_back({cur, cur+d-1, py-cur});
                py += d;
            }
        }
    }
    for(auto &t: V){
        //printf("%d %d %d\n",t.b,t.e,t.d);
        U.push_back({t.b, t.d, 1});
        U.push_back({t.e+1, t.d, -1});
    }
    sort(U.begin(),U.end());
    for(i=1;i<=m;i++){
        scanf("%d%d",&B[i].x,&B[i].y);
        B[i].num=i;       
    }
    sort(B+1,B+m+1);
    int pv = 0;
    for(i=1;i<=m;i++){
        while(pv<U.size() && U[pv].x <= B[i].x){
            MM[U[pv].y]+=U[pv].c;
            pv++;
        }
        if(MM[B[i].y-B[i].x] > 0)Res[B[i].num] = 1;
    }
    for(i=1;i<=m;i++){
        printf(Res[i]?"LOSE\n":"WIN\n");
    }
}