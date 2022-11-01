#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=5e5+5,mod=998244353;
vector<pair<int,int>>mov;
int kx,ky;
vector<pair<int,int>>st;
bool judge(int x,int y,int sx,int sy)
{
    if(sx<1||sx>8||sy<1||sy>8) return false;
    if(sx==x||sy==y||abs(sx-x)==abs(sy-y)) return false;
    return true;
}
bool test;
void query(int x,int y)
{
    if(test)
    {
        random_shuffle(st.begin(),st.end());
        for(pair<int,int>s:st)
        {
            if(judge(x,y,kx+s.first,ky+s.second))
            {
                kx+=s.first;
                ky+=s.second;
                mov.push_back(s);
                return;
            }
        }
        mov.push_back({0,0});
        return;
    }
    printf("%d %d\n",x,y);
    fflush(stdout);
    char s[10];
    scanf("%s",s);
    string ss=s;
    if(ss=="Right") mov.push_back({0,1});
    else if(ss=="Left") mov.push_back({0,-1});
    else if(ss=="Up") mov.push_back({-1,0});
    else if(ss=="Down") mov.push_back({1,0});
    else if(ss=="Down-Right") mov.push_back({1,1});
    else if(ss=="Down-Left") mov.push_back({1,-1});
    else if(ss=="Up-Left") mov.push_back({-1,-1});
    else if(ss=="Up-Right") mov.push_back({-1,1});
    else mov.push_back({0,0});
}
void sol(int cas)
{
    if(test)
    {
        kx=rand()%8+1;ky=rand()%8+1;
        // cout<<"King: "<<kx<<' '<<ky<<endl;
    }
    mov.clear();
    vector<int>vx,vy;
    rep(i,1,8) vx.push_back(i),vy.push_back(i);
    random_shuffle(vx.begin(),vx.end());
    random_shuffle(vy.begin(),vy.end());
    int x=1,y=1,gx=vx.back(),gy=vy.back();
    // cout<<"G: "<<gx<<' '<<gy<<endl;
    vx.pop_back();
    vy.pop_back();
    query(x,y);
    while(mov.back()!=make_pair(0,0))
    {
        // cout<<"Cur: "<<x<<' '<<y<<endl;
        gx+=mov.back().first;
        gy+=mov.back().second;
        while(gx==x||gx<1||gx>8)
        {
            assert(vx.size()!=0);
            gx=vx.back();
            // cout<<"guess x: "<<gx<<endl;
            vx.pop_back();
            for(pair<int,int>s:mov)
            {
                gx+=s.first;
                if(gx<1||gx>8) break;
            }
        }
        while(gy==y||gy<1||gy>8)
        {
            assert(vy.size()!=0);
            gy=vy.back();
            // cout<<"guess y: "<<gy<<endl;
            vy.pop_back();
            for(pair<int,int>s:mov)
            {
                gy+=s.second;
                if(gy<1||gy>8) break;
            }
        }
        assert(gx>=1&&gx<=8);
        assert(gy>=1&&gy<=8);
        int dx=0,dy=0;
        if(gx<x&&gx!=x-1) dx=-1;
        if(gx>x&&gx!=x+1) dx=1;
        if(gy<y&&gy!=y-1) dy=-1;
        if(gy>y&&gy!=y+1) dy=1;
        // cout<<dx<<' '<<dy<<endl;
        if(dx||dy)
        {
            x+=dx;
            y+=dy;
            query(x,y);
        }
        else
        {
            random_shuffle(st.begin(),st.end());
            for(pair<int,int>s:st)
            if(x+s.first>=1&&x+s.first<=8&&y+s.second>=1&&y+s.second<=8)
            {
              x+=s.first;
              y+=s.second;
              break;
            }
            query(x,y);
        }
    }
    if(test) cout<<"Win: "<<mov.size()<<endl;
}
int main()
{
    // test=true;
    st.push_back({0,1});
    st.push_back({0,-1});
    st.push_back({-1,0});
    st.push_back({1,0});
    st.push_back({1,1});
    st.push_back({1,-1});
    st.push_back({-1,-1});
    st.push_back({-1,1});
//   freopen("1.in", "r",stdin);
  // freopen("2.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
  scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/