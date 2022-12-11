#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char A[210000],B[210000];
void get(char *A,int l,int r){
    if ((r-l+1)&1) return;
    int mid=l+r>>1;
    get(A,l,mid); get(A,mid+1,r);
    for (int i=1;i<=r-mid;i++) if (A[l+i-1]>A[mid+i]) break; else if (A[l+i-1]<A[mid+i]) return;
    for (int i=1;i<=r-mid;i++) swap(A[l+i-1],A[mid+i]);
}
int main(){
    scanf("%s",A+1); scanf("%s",B+1);
    int n=strlen(A+1);
    get(A,1,n); get(B,1,n);
    for (int i=1;i<=n;i++) if (A[i]!=B[i]) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}