#include<cstdio>
#include<algorithm>
#define SZ 1048576
using namespace std;
int TC, C[1010000], BS = 500000, S[501000], IT[SZ+SZ];
char p[501000];
void Add(int a, int b){
    a+=SZ;
    IT[a]+=b;
    while(a!=1){
        a>>=1;
        IT[a]=min(IT[a*2],IT[a*2+1]);
    }
}
int Min(int b, int e){
    int r=1e9;
    b+=SZ,e+=SZ;
    while(b<=e){
        r=min(r,min(IT[b],IT[e]));
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
bool Pos(int b, int e, int Mn, int Mx){
    //printf("\n%d %d %d %d\n",b,e,Mn,Mx);
    if(IT[1]<0)return false;
    if(b>e)swap(b,e);
    return Min(Mn,b-1)>=2 && Min(b,e-1)>=1 && Min(e,Mx-1)>=2;
}
void Solve(){
    scanf("%s",p);
    int t = BS;
    int i, n;
    int Mn=BS, Mx=BS;
    S[0]=t;
    for(i=0;p[i];i++){
        if(p[i]=='0')t--;
        else t++;
        S[i+1]=t;
        Mn=min(Mn,t);
        Mx=max(Mx,t);
    }
    n = i;
    for(i=1;i<=n;i++){
        Add(min(S[i-1],S[i]), 1);
    }
    for(i=0;i<=n;i++)C[S[i]]++;
    t = BS;

    for(i=0;i<n;i++){
        C[t]--;
        while(!C[Mn]){
            Mn++;
        }
        while(!C[Mx]){
            Mx--;
        }
        if(t-1 < Mn){
            printf("1");
            Add(t,-1);
            t++;
        }
        else if(t+1 > Mx){
            printf("0");
            t--;
            Add(t,-1);
        }
        else{
            Add(t-1,-1);
            if(Pos(t-1, S[n], Mn, Mx)){
                printf("0");
                t--;
            }
            else{
                Add(t-1,1);
                Add(t,-1);
                printf("1");
                t++;
            }
        }
    }
    puts("");
    for(i=BS-n;i<=BS+n;i++){
        C[i]=0;
    }
}
int main(){
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}