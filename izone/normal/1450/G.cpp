#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, A, B, C[20], NN[200];
int BB[22], EE[22];
char p[5010], q[22] = "acdefhijklmnopqsvwxz";
int P[1<<20], D[1<<20], Bv[1<<20], Ev[1<<20], Cv[1<<20];
bool Pos(int b, int e, int c){
    return c>0 && (e-b+1)*A <= c*B;
}
void Solve(){
    int i, j;
    for(i=0;i<20;i++){
        NN[q[i]]=i;
        BB[i]=EE[i]=-1;
    }
    scanf("%d%d%d",&n,&A,&B);
    scanf("%s",p);
    for(i=0;i<n;i++){
        int ch = NN[p[i]];
        if(BB[ch]==-1)BB[ch]=i;
        EE[ch]=i;
        C[ch]++;
    }
    for(i=0;i<(1<<20);i++){
        int b=  1e9, e = -1e9;
        for(j=0;j<20;j++){
            if(C[j] && ((i>>j)&1)){
                b=min(b,BB[j]);
                e=max(e,EE[j]);
                Cv[i]+=C[j];
            }
        }
        Bv[i]=b,Ev[i]=e;
    }
    int full=0;
    for(i=0;i<20;i++){
        if(C[i])full|=(1<<i);
    }
    P[0]=1;
    for(i=0;i<(1<<20);i++){
        if(!P[i])continue;
        //printf("%d\n",i);
        for(j=0;j<20;j++){
            if(!C[j])continue;
            if((i>>j)&1)continue;
            if((D[i]>>j)&1)continue;
            int b = min(Bv[i],BB[j]);
            int e = max(Ev[i],EE[j]);
            //printf("%d %d %d\n",b,e,Cv[i]+C[j]);
            if(Pos(b, e, Cv[i]+C[j])){
                D[i]|=(1<<j);
            }
        }
        for(j=0;j<20;j++){
            if(!C[j])continue;
            if((i>>j)&1)continue;
            D[i|(1<<j)]|=D[i];
            if(!((D[i]>>j)&1))continue;
            P[i|(1<<j)]=1;
        }
    }
    vector<char>R;
    for(i=0;i<20;i++){
        if(C[i] && P[(full - (1<<i))]){
            R.push_back(q[i]);
        }
    }
    printf("%d ",R.size());
    for(auto &t : R)printf("%c ",t);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}