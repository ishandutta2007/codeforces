#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
bitset<1010000>A[1010];
vector<int>L,R,U,D;
int w[1010];
bool Go(int n, vector<int>&P, vector<int>&Q){
    int i, a;
    P.clear();
    Q.clear();
    for(i=0;i<=n;i++)A[i].reset();
    A[0][0]=1;
    int sum=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
        A[i]=(A[i-1])|(A[i-1]<<w[i]);
    }
    if(sum%2 || A[n][sum/2]==0)return false;
    int pv = sum/2;
    for(i=n;i>=1;i--){
        if(pv>=w[i] && A[i-1][pv-w[i]]){
            P.push_back(w[i]);
            pv-=w[i];
        }
        else{
            Q.push_back(w[i]);
        }
    }
    return true;
}
struct point{
    int x, y;
};
void Solve(){
    int n, m;
    int i, j, ck=0;
    scanf("%d",&n);
    if(!Go(n,L,R))ck=1;
    scanf("%d",&m);
    if(!Go(m,U,D))ck=1;
    if(ck || n!=m){
        puts("No");
        return;
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    sort(U.begin(),U.end());
    sort(D.begin(),D.end());
    if(L.size()>R.size())swap(L,R);
    if(U.size()>D.size())swap(U,D);
    if(L.size()<U.size()){
        swap(L,U);
        swap(R,D);
        ck=1;
    }

    int sL = 0, sR = 0, pL = 0, pR = 0;
    for(i=0;i<=U.size();i++){
        if(sL < sR){
            sL+=L[pL];
            pL++;
        }
        else{
            sR+=R[pR];
            pR++;
        }
    }
    vector<point>Res;
    int x = 0, y = 0;
    Res.push_back({x,y});
    for(i=0;i<pL;i++){
        x-=L[i];
        Res.push_back({x,y});
        y+=U[i];
        Res.push_back({x,y});
    }
    for(i=0;i<pR;i++){
        x+=R[i];
        Res.push_back({x,y});
        if(i+1==pR)break;
        y+=U[pL+i];
        Res.push_back({x,y});
    }
    int dd = 0;
    for(i=pR;i<R.size();i++){
        y-=D[dd];
        Res.push_back({x,y});
        dd++;
        x+=R[i];
        Res.push_back({x,y});
    }
    for(i=pL;i<L.size();i++){
        y-=D[dd];
        Res.push_back({x,y});
        dd++;
        x-=L[i];
        Res.push_back({x,y});
    }
    if(ck){
        for(i=0;i<Res.size();i++)swap(Res[i].x,Res[i].y);
    }
    puts("Yes");
    for(auto &t: Res)printf("%d %d\n",t.x,t.y);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}