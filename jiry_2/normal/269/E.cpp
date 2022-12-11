#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>C[410000];
int go[410000],n,m,pd[410000],B[5],ansX[410000],ansY[410000],now,num,cho[410000],bo[410000],a[410000],b[410000],D[410000],E[410000];
struct atom2{
    int w1; unsigned long long w2; int where;
}x[410000],y[410000];
vector<int>t[410000],s[410000],sw[410000],tw[410000];
char getin(){
    char ch=getchar(); while (ch<'A'||ch>'Z') ch=getchar(); return ch;
}
struct point{
    int x,y;
};
struct atom{
    point k1,k2;
    void scan(){
        char k3=getin(),k4=getin(); scanf("%d%d",&k1.y,&k2.y);
        if (k3=='L') k1.x=1; else if (k3=='R') k1.x=0; else if (k3=='T') k1.x=2; else k1.x=3;
        if (k4=='L') k2.x=1; else if (k4=='R') k2.x=0; else if (k4=='T') k2.x=2; else k2.x=3;
        if (k1.x>k2.x) swap(k1,k2);
    }
}A[410000];
int get(point k1){
    if (k1.x==1) return k1.y;
    if (k1.x==2) return k1.y+n;
    if (k1.x==0) return k1.y+n+m;
    return k1.y+n+n+m;
}
int getnext(int k){
    k+=n+m;
    if (k>n+n+m+m) k-=n+n+m+m;
    return k;
}
int getlin(int k){
    if (k>n+m) k-=n+m; return k;
}
void find(int k1,int k2){
    int k3=getlin(k1);
    if (pd[k3]) return;
    pd[k3]=1; C[k2].push_back(k3); find(getnext(go[k1]),k2);
}
int gcd(int k1,int k2){
    if (k2==0) return k1; return gcd(k2,k1%k2);
}
int check(int k){
    int num=0;
    for (int i=0;i<C[k].size();i++){
        int k1=(i+1)%C[k].size();
        if (C[k][i]>n&&C[k][k1]>n&&(C[k][i]<=n+m||C[k][i]>n+n+m)&&(C[k][k1]<=n+m||C[k][k1]>n+n+m)) num++;
    }
    return num;
}
void print(int k1,int k2,int k3){
    if (ansY[k1]) return;
//    cout<<"print "<<k1<<" "<<k2<<" "<<k3<<endl;
    ansY[k1]=k2; cho[k2]=1;
    if (go[k1+n]>n+n+m){
        k2+=num; print(getnext(go[k1+n])-n,k2,k3+1); return;
    }
    k2=n-(m-k2); print(getnext(go[getnext(go[k1+n])])-n,k2,k3);
}
int check2(int k){
    int k1=C[k][0];
    if (go[k1]<=n+m){
        k1=go[getnext(go[k1])]; 
        if (k1>n) return 0;
        k1=go[getnext(k1)];
        if (k1<=n+n+m) return 0;
        return 1;
    } else {
        k1=go[getnext(go[k1])];
        if (k1>n) return 0;
        k1=go[getnext(k1)];
        if (k1>n+m) return 0;
        return 1;
    }
}
void findf(int k,int k1){
//  cout<<k<<" "<<k1<<endl;
    if (pd[k]) return;
    pd[k]=1; sw[k1].push_back(k);
    if (m-k+1<=B[1]){s[k1].push_back(0); findf(n-(m-k),k1); return;}
    s[k1].push_back(1); findf(k+num,k1);
}
void findf2(int k,int k1){
    if (pd[k]) return; pd[k]=1; tw[k1].push_back(k);
    if (go[k+n]>n+n+m){t[k1].push_back(1); findf2(getlin(go[k+n])-n,k1); return;}
    t[k1].push_back(0); findf2(getnext(go[getnext(go[k+n])])-n,k1);
}
int findmin(vector<int> &s){
    int len=s.size(),i=0,j=1,k=0;
    while (i<len&&j<len&&k<len){
        int k1=(i+k)%len,k2=(j+k)%len;
        if (s[k1]==s[k2]) k++;
        else{
            if (s[k1]>s[k2]) i+=k+1; else j+=k+1;
            if (i==j) j++; k=0;
        }
    }
    return min(i,j);
}
int getw1(vector<int> &s,int first){
    int num=0,key=97,mo=1e9+7;
    for (int i=0;i<s.size();i++) num=(1ll*num*key+s[(first+i)%(s.size())])%mo;
    return num;
}
unsigned long long getw2(vector<int> &s,int first){
    unsigned long long num=0,key=37;
    for (int i=0;i<s.size();i++) num=num*key+s[(first+i)%(s.size())];
    return num;
}
int compare(atom2 k1,atom2 k2){
    return (k1.w1<k2.w1)||(k1.w1==k2.w1&&k1.w2<k2.w2);
}
int main(){
    scanf("%d%d",&n,&m);
    int flag1=0,flag2=0;
    for (int i=1;i<=n+m;i++){
        A[i].scan(); if (A[i].k1.x==0&&A[i].k2.x==1) flag1=1;
        if (A[i].k1.x==2&&A[i].k2.x==3) flag2=1;
    }
    int flag=0;
    if (flag1&&flag2){cout<<"No solution"<<endl; return 0;}
    if (flag1){
        flag++; 
        for (int i=1;i<=n+m;i++){
            A[i].k1.x=3-A[i].k1.x; A[i].k2.x=3-A[i].k2.x;
            swap(A[i].k1,A[i].k2);
        }
        swap(n,m);
    }
    num=0;
    for (int i=1;i<=n+m;i++)
        if (A[i].k1.x==1&&A[i].k2.x==2) num--; else if (A[i].k1.x==1&&A[i].k2.x==3) num++;
    if (num<0){
        flag+=2; num=-num;
        for (int i=1;i<=n+m;i++){
            if (A[i].k1.x<=1) A[i].k1.y=n-A[i].k1.y+1; else A[i].k1.x=5-A[i].k1.x;
            if (A[i].k2.x<=1) A[i].k1.y=n-A[i].k2.y+1; else A[i].k2.x=5-A[i].k2.x;
            if (A[i].k1.x>A[i].k2.x) swap(A[i].k1,A[i].k2);
        }
    }
    for (int i=1;i<=n+m;i++){
        if (A[i].k1.x==1&&A[i].k2.x==2) B[0]++;
        if (A[i].k1.x==0&&A[i].k2.x==2) B[1]++;
        if (A[i].k1.x==0&&A[i].k2.x==3) B[2]++;
        if (A[i].k1.x==1&&A[i].k2.x==3) B[3]++;
        if (A[i].k1.x==2&&A[i].k2.x==3) B[4]++;
    }
    if (B[0]!=B[2]||B[1]!=B[3]){cout<<"No solution"<<endl; return 0;}
    if (n==1&&m==1){cout<<1<<endl; cout<<1<<endl; return 0;}
    for (int i=1;i<=n+m;i++){
        int k1=get(A[i].k1),k2=get(A[i].k2);
        go[k1]=k2; go[k2]=k1;
    }
    memset(pd,0x00,sizeof pd); int len=0; 
    for (int i=1;i<=n+m;i++) if (pd[i]==0){len++; find(i,len);}
    int len2=0; if (B[4]||num) len2=B[4]/(gcd(B[4],num)); else len2=1; now=0; 
    memset(pd,0x00,sizeof pd); int now=0;
//    if (n==100000&&m==100000) cout<<1<<" "<<B[4]<<" "<<num<<endl;
/*    for (int i=1;i<=len;i++){
        for (int j=0;j<C[i].size();j++) cout<<C[i][j]<<" "; cout<<endl;}*/
    if (B[4]==0){
        int now1=B[0];
        for (int i=1;i<=len;i++){
            int k1=check(i);
//          if (n==100000&&m==100000&&C[i].size()==2) cout<<C[i][0]<<" "<<C[i][1]<<endl;
            if (k1==0&&C[i].size()==4&&check2(i)){
            //  cout<<"great "<<i<<" "<<C[i][1]<<" "<<C[i][3]<<endl;
                now++; ansY[C[i][1]-n]=now; ansY[C[i][3]-n]=m-now+1; bo[i]=1;
            } else if (C[i].size()==2&&k1==0&&C[i][0]<=n&&C[i][1]>n&&C[i][1]<=n+m){
                if (n!=m){cout<<"No solution"<<endl; return 0;}
                ansY[C[i][1]-n]=++now1;
            } else {cout<<"No solution"<<endl; return 0;}
        }
    } else {
        for (int i=1;i<=len;i++){
            int k1=check(i);
            if (k1==0&&C[i].size()==4&&check2(i)){
            //  cout<<"great "<<i<<" "<<C[i][1]<<" "<<C[i][3]<<endl;
                now++; ansY[C[i][1]-n]=now; ansY[C[i][3]-n]=m-now+1; bo[i]=1;
            } else if (k1!=len2||k1==0){
                cout<<"No solution"<<endl; return 0;
            }
        }
    }
    if (B[4]==0){
        for (int i=1;i<=n;i++) if (go[i]<=n+m) ansX[i]=ansY[go[i]-n]; else ansX[i]=n-(ansY[go[i]-n-n-m])+1;
        for (int i=1;i<=n;i++) a[ansX[i]]=i;
        for (int i=1;i<=m;i++) b[ansY[i]]=i;
        if (flag&2){
            for (int i=1;i<n-i+1;i++) swap(a[i],a[n-i+1]);
            for (int i=1;i<=n;i++) a[i]=n-a[i]+1;
        }
        if (flag&1){
            for (int i=1;i<=m;i++) printf("%d ",b[i]); cout<<endl;
            for (int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
        } else {
            for (int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
            for (int i=1;i<=m;i++) printf("%d ",b[i]); cout<<endl;
        }
        return 0;
    }
    int len3=B[4]/len2;
    memset(pd,0x00,sizeof pd);
    for (int i=1;i<=len3;i++) findf(i+B[0],i);
    for (int i=1;i<=len3;i++) D[i]=findmin(s[i]);
    int len4=0;
    memset(pd,0x00,sizeof pd);
    for (int i=1;i<=m;i++) if (go[i+n]>n+n+m&&pd[i]==0) findf2(i,++len4);
    for (int i=1;i<=len4;i++) E[i]=findmin(t[i]);
//    cout<<len3<<" "<<len4<<endl;
    for (int i=1;i<=len3;i++) x[i]=(atom2){getw1(s[i],D[i]),getw2(s[i],D[i]),i};
    for (int i=1;i<=len4;i++) y[i]=(atom2){getw1(t[i],E[i]),getw2(t[i],E[i]),i};
/*    for (int i=1;i<=len3;i++){
        for (int j=0;j<s[i].size();j++) cout<<s[i][j]<<" "; cout<<D[i]<<endl;}
    cout<<endl;
    for (int i=1;i<=len4;i++){
        for (int j=0;j<t[i].size();j++) cout<<t[i][j]<<" "; cout<<E[i]<<endl;}
    cout<<endl;*/
    sort(x+1,x+len3+1,compare); sort(y+1,y+len4+1,compare);
//    for (int i=1;i<=m;i++) cout<<ansY[i]<<" "; cout<<endl;
 //   if (n==100000&&m==100000) cout<<1<<endl;
    if (len3!=len4){cout<<"No solution"<<endl; return 0;} 
    for (int i=1;i<=len4;i++){
        if (x[i].w1!=y[i].w1||x[i].w2!=y[i].w2){cout<<"No solution"<<endl; return 0;}
//      cout<<tw[y[i].where][E[y[i].where]]<<" "<<sw[x[i].where][D[x[i].where]]<<endl;
        print(tw[y[i].where][E[y[i].where]],sw[x[i].where][D[x[i].where]],0);
    }
//    if (n==100000&&m==100000) cout<<1<<endl;
//    for (int i=1;i<=m;i++) cout<<ansY[i]<<" "; cout<<endl;
    for (int i=1;i<=n;i++) if (go[i]<=n+m) ansX[i]=ansY[go[i]-n]; else ansX[i]=n-(ansY[go[i]-n-n-m])+1;
    for (int i=1;i<=n;i++) a[ansX[i]]=i;
    for (int i=1;i<=m;i++) b[ansY[i]]=i;
    if (flag&2){
        
        for (int i=1;i<n-i+1;i++) swap(a[i],a[n-i+1]);
        for (int i=1;i<=n;i++) a[i]=n-a[i]+1;
    }
    if (flag&1){
        for (int i=1;i<=m;i++) printf("%d ",b[i]); cout<<endl;
        for (int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
    } else {
        for (int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
        for (int i=1;i<=m;i++) printf("%d ",b[i]); cout<<endl;
    }
    return 0;
}