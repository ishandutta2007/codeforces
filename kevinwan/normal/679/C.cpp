#include<bits/stdc++.h>
using namespace std;
const int mn=510;
string s[mn];
int p[mn*mn],siz[mn*mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    if(siz[a]<siz[b])swap(a,b);
    siz[a]+=siz[b];
    siz[b]=0;
    p[b]=a;
}
int n,k;
inline int h(int r,int c){
    if(r<0||c<0||r>=n||c>=n)return n*n;
    else return r*n+c;
}
int sc[mn][mn],psa[mn][mn];
inline int ps(int r,int c){
    return (r>=0&&c>=0)?psa[r][c]:0;
}
inline int qu(int r,int c){
    return ps(r,c)-ps(r-k,c)-ps(r,c-k)+ps(r-k,c-k);
}
int num[mn*mn];
int cur;
void hail(int r,int c){
    int x=f(h(r,c));
    if(num[x]==0)cur+=siz[x];
    num[x]++;
}
void rhail(int r,int c){
    int x=f(h(r,c));
    num[x]--;
    if(num[x]==0)cur-=siz[x];
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)cin>>s[i];
    iota(p,p+mn*mn,0);
    fill(siz,siz+mn*mn,1);
    siz[h(-1,-1)]=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(j+1!=n&&s[i][j]=='.'&&s[i][j+1]=='.')u(h(i,j),h(i,j+1));
        if(i+1!=n&&s[i][j]=='.'&&s[i+1][j]=='.')u(h(i,j),h(i+1,j));
        if(s[i][j]!='.')siz[h(i,j)]=0;
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)psa[i][j]=(s[i][j]=='.');
    for(int i=1;i<=n;i++)psa[i][0]+=psa[i-1][0],psa[0][i]+=psa[0][i-1];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)psa[i][j]+=psa[i][j-1]+psa[i-1][j]-psa[i-1][j-1];
    for(int i=0;i<=n-k;i++)for(int j=0;j<=n-k;j++)sc[i][j]=k*k-qu(i+k-1,j+k-1);
    for(int i=0;i<=n-k;i++){
        memset(num,0,sizeof(num));
        cur=0;
        for(int j=0;j<k;j++)for(int l=-1;l<k+1;l++)hail(i+j,l);
        for(int j=-1;j<k+1;j++)for(int l=0;l<k;l++)hail(i+j,l);
        sc[i][0]+=cur;
        for(int j=1;j<=n-k;j++){
            for(int l=0;l<k;l++){
                rhail(i+l,j-2);
                hail(i+l,j+k);
            }
            for(int l=-1;l<k+1;l++){
                rhail(i+l,j-1);
                hail(i+l,j+k-1);
            }
            sc[i][j]+=cur;
        }
    }
    int ans=0;
    for(int i=0;i<=n-k;i++)for(int j=0;j<=n-k;j++)ans=max(ans,sc[i][j]);
    printf("%d",ans);
}