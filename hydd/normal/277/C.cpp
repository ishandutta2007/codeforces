#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,num,Rlen[110000],Clen[110000];
int cntr,cntc,nR[110000],nC[110000];
map<int,int> R,C;
vector<pii> r[110000],c[110000];
int calc(vector<pii> &vec,int n){
    sort(vec.begin(),vec.end());
    int res=0,pos=0;
    for (pii v:vec){
        res+=max(v.first-pos,0);
        pos=max(pos,v.second);
    }
    return res+max(n-pos,0);
}
int calc(map<int,int> &mp){
    int res=1;
    for (pii v:mp){
        if (v.first!=res) break;
        res=v.first+1;
    }
    return res;
}
int getpos(vector<pii> &vec,int m,int n){
    sort(vec.begin(),vec.end());
    int res=0,pos=0;
    for (pii v:vec){
        res+=max(v.first-pos,0);
        if (res>=m) return v.first-(res-m);
        pos=max(pos,v.second);
    }
    return n-(res+max(n-pos,0)-m);
}
void print(){
    for (int i=1;i<=cntr;i++)
        if (Rlen[i]>(num^Rlen[i])){
            int tmp=getpos(r[i],Rlen[i]-(num^Rlen[i]),m);
            printf("%d %d %d %d\n",nR[i],0,nR[i],tmp);
            return;
        }
    for (int i=1;i<=cntc;i++)
        if (Clen[i]>(num^Clen[i])){
            int tmp=getpos(c[i],Clen[i]-(num^Clen[i]),n);
            printf("%d %d %d %d\n",0,nC[i],tmp,nC[i]);
            return;
        }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int x1,y1,x2,y2;
    for (int i=1;i<=k;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2){
            if (R.find(x1)==R.end()) R[x1]=++cntr,nR[cntr]=x1;
            if (y1>y2) swap(y1,y2);
            r[R[x1]].push_back(pii(y1,y2));
        } else{
            if (C.find(y1)==C.end()) C[y1]=++cntc,nC[cntc]=y1;
            if (x1>x2) swap(x1,x2);
            c[C[y1]].push_back(pii(x1,x2));
        }
    }
    num=(((n-1-cntr)&1?m:0)^((m-1-cntc)&1?n:0));
    for (int i=1;i<=cntr;i++) Rlen[i]=calc(r[i],m),num^=Rlen[i];
    for (int i=1;i<=cntc;i++) Clen[i]=calc(c[i],n),num^=Clen[i];
    // cerr<<num<<endl;
    if (num){
        puts("FIRST");
        if (cntr<n-1&&m>(num^m)){
            int r=calc(R);
            printf("%d %d %d %d\n",r,0,r,m-(num^m));
        }
        else
            if (cntc<m-1&&n>(num^n)){
                int c=calc(C);
                printf("%d %d %d %d\n",0,c,n-(num^n),c);
            }
            else print();
    } else puts("SECOND");
    return 0;
}