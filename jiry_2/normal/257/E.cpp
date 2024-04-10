#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct atom{
    int where,t,s,f;
}x[100100];
int n,m,where;
long long ans[100100],t;
int compare(atom k1,atom k2){
    return k1.t<k2.t;
}
struct atom2{
    int where,s;
};
int operator < (atom2 k1,atom2 k2){
    return k1.s<k2.s;
}
multiset<atom2>Lin,Rin,Lout,Rout;
void get(long long lim){
    //cout<<"find "<<t<<" "<<lim<<endl;
    multiset<atom2>::iterator k1,k2;
    while (!Lin.empty()||!Lout.empty()||!Rin.empty()||!Rout.empty())
        if (Lin.size()+Lout.size()>Rin.size()+Rout.size()){
            //cout<<"DOWN"<<endl;
            int ans1=0,pd=0;
            if (!Lin.empty()){k1=Lin.end(); k1--; if ((*k1).s>ans1){ans1=(*k1).s; pd=1;}}
            if (!Lout.empty()){k1=Lout.end(); k1--; if ((*k1).s>ans1){ans1=(*k1).s; pd=2;}}
            int ti=where-ans1; if (ti+t>lim) {where-=lim-t; return;} t+=ti; where=ans1;
            while (!Lin.empty()){
                k1=Lin.end(); k1--; if ((*k1).s!=where) break;
                ans[x[(*k1).where].where]=t; Lin.erase(k1);
            }
            while (!Lout.empty()){
                k1=Lout.end(); k1--; if ((*k1).s!=where) break;
                int k3=x[(*k1).where].f;
                if (k3>where) Rin.insert((atom2){(*k1).where,k3}); else Lin.insert((atom2){(*k1).where,k3}); Lout.erase(k1);
            }
        } else {
            //cout<<"UP"<<endl;
            int ans1=m+1,pd=0;
            if (!Rin.empty()){k1=Rin.begin(); if ((*k1).s<ans1){ans1=(*k1).s; pd=1;}}
            if (!Rout.empty()){k1=Rout.begin(); if ((*k1).s<ans1){ans1=(*k1).s; pd=2;}} //cout<<ans1<<" "<<where<<" "<<t<<" "<<lim<<endl;
            int ti=-where+ans1; if (ti+t>lim) {where+=lim-t; return;} t+=ti; where=ans1;
            while (!Rin.empty()){
                k1=Rin.begin(); if ((*k1).s!=where) break;
                ans[x[(*k1).where].where]=t; Rin.erase(k1);
            }
            while (!Rout.empty()){
                k1=Rout.begin(); if ((*k1).s!=where) break;
                int k3=x[(*k1).where].f;
                if (k3>where) Rin.insert((atom2){(*k1).where,k3}); else Lin.insert((atom2){(*k1).where,k3}); Rout.erase(k1);
            }
        }
}
int main(){
    scanf("%d%d",&n,&m); for (int i=1;i<=n;i++){scanf("%d%d%d",&x[i].t,&x[i].s,&x[i].f); x[i].where=i;}
    sort(x+1,x+n+1,compare); where=1; t=1;
    for (int i=1;i<=n;i++){
        t=x[i].t;// cout<<i<<" "<<where<<" "<<t<<endl;
        if (where>x[i].s) Lout.insert((atom2){i,x[i].s}); else if (where<x[i].s) Rout.insert((atom2){i,x[i].s}); 
        else if (where>x[i].f) Lin.insert((atom2){i,x[i].f}); else Rin.insert((atom2){i,x[i].f});
        if (i<n) get(x[i+1].t); else get(1e18);
    }
    for (int i=1;i<=n;i++) printf("%I64d\n",ans[i]); return 0;
}