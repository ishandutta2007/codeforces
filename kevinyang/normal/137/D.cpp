#include <bits/stdc++.h>

using namespace std;
char in[510];
int dp[510][510];
int smt[510][510];
int pointTo[510][510];
int n;
int check(int l,int r){
    int change=0;
    for(int i=l; i<=(l+r)/2; i++){
        if(in[i]!=in[r-i+l])change++;
    }
    return change;
}
int f(int l,int k){
    if(dp[l][k]!=-1)return dp[l][k];
    if(k==0&&l==n)return 0;
    if(k==0)return 1e9;
    if(l==n)return 0;
    int d=1e9;
    for(int r=l; r<n; r++){
        if(smt[l][r]+f(r+1,k-1)<d){
            d=smt[l][r]+f(r+1,k-1);
            pointTo[l][k]=r+1;
        }
    }
    return dp[l][k]=d;
}
void print(int l,int r){
    for(int i=l; i<l+(r-l+1)/2; i++){
        printf("%c",in[r-i+l]);
    }
    for(int i=l+(r-l+1)/2; i<=r; i++){
        printf("%c",in[i]);
    }
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%s",in);
    n=strlen(in);
    int k;
    scanf("%d",&k);
    for(int l=0; l<n; l++){
        for(int r=l; r<n; r++){
            smt[l][r]=check(l,r);
            // printf("%d %d %d\n",l,r,smt[l][r]);
        }
    }
    printf("%d\n",f(0,k));
    int kk=k,ii=0;
    while(ii!=n){
        int rr=pointTo[ii][kk--];
        // printf("%d %d\n",ii,rr);
        print(ii,rr-1);
        if(rr!=n)printf("+");
        ii=rr;
    }

    return 0;
}