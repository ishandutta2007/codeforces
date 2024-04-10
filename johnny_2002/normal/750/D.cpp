#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=33;
const int maxval=305;
const int BASE=1000;

const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};


int n,a[N];
bool h[maxval][maxval][N][10][6];


int hans[maxval][maxval];
queue <ll> q;

void assigned(int &x,int &y,int &cur,int &dir,int &rem,ll val){
//    assert(val>=0);
    rem=val%BASE;val/=BASE;
    dir=val%BASE;val/=BASE;
    cur=val%BASE;val/=BASE;
    y=val%BASE;val/=BASE;
    x=val;
//    assert(x>=0&&x<maxval);
//    assert(y>=0&&y<maxval);
//    assert(cur>0&&cur<=n);
//    assert(dir>=0&&dir<8);
//    assert(rem>0&&rem<=5);
}
ll gethash(int x,int y,int cur,int dir,int rem){
    assert(x>=0&&x<maxval);
    assert(y>=0&&y<maxval);
    ll ans=x;
    ans=ans*BASE+y;
    ans=ans*BASE+cur;
    ans=ans*BASE+dir;
    ans=ans*BASE+rem;
//    assert(ans>=0);
    return ans;
}
void checkh(int x,int y,int cur,int dir,int rem){
    if (!h[x][y][cur][dir][rem]){
//            cout<<x<<" "<<y<<" "<<cur<<" "<<dir<<" "<<rem<<'\n';
        h[x][y][cur][dir][rem]=1;
        ll nval=gethash(x,y,cur,dir,rem);
        q.push(nval);
    }
}
void process(ll val){
//    cout<<val<<'\n';
    int x,y,cur,dir,rem;
    assigned(x,y,cur,dir,rem,val);
//    cout<<x<<" "<<y<<" "<<cur<<" "<<dir<<" "<<rem<<'\n';
    if (!hans[x][y]) hans[x][y]=1;
    if (rem>1){
        rem--;
        x+=dx[dir];
        y+=dy[dir];
        checkh(x,y,cur,dir,rem);
        return;
    }
    if (cur==n) return;
    for(int i=-1;i<=1;i+=2){
        int ndir=(dir+i+8)%8;
        checkh(x+dx[ndir],y+dy[ndir],cur+1,ndir,a[cur+1]);
    }
//    cout<<"!\n";
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    checkh(152,152,1,1,a[1]);
    while (!q.empty()){
        ll x=q.front();q.pop();
        process(x);
//        cout<<"=>"<<q.size()<<'\n';
    }
    int ans=0;
    for(int i=0;i<maxval;i++)
        for(int j=0;j<maxval;j++) ans+=hans[i][j];
    cout<<ans;
}