#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
typedef map<char,int>mci;
typedef priority_queue<ppi,vppi,greater<ppi>> min_heap_ppi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define deb2(x,y) cout<<x<<" "<<y
#define d2(x,y) cout<<x<<" "<<y<<endl
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define d4(a,b,c,d) deb2(a,b);deb2(c,d);d1("")
#define d5(a,b,c,d,e) deb2(a,b);deb2(c,d);d1(e)
#define d6(a,b,c,d,e,f) deb2(a,b);deb2(c,d);deb2(e,f);d1("")
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
//#define file cin

const int maxn=1000050;
const int MaxN=maxn/10;
// const int maxm=1e16;
int arr[maxn],dp[4][maxn],cnt[4][maxn];
mci dd;
vi h,a,r,d;


signed main(){
    int n,ans=0;
    string s;
    cin>>n;
    cin>>s;
    dd['h']=0;
    dd['a']=1;
    dd['r']=2;
    dd['d']=3;
    
    For(i,n) {
        if (i!=0) For(j,4) cnt[j][i]=cnt[j][i-1];
        else For(j,4) cnt[j][i]=0;
        cin>>arr[i];
        if (dd.find(s[i])!=dd.end()) cnt[dd[s[i]]][i]++;
        if (s[i]=='h') h.pb(i);
        if (s[i]=='a') a.pb(i);
        if (s[i]=='r') r.pb(i);
        if (s[i]=='d') d.pb(i);
        For(j,4) dp[j][i]=0;
    }
    if (h.size() && r.size() && a.size() && d.size()){
    
    For(i,h.size()-1){
        int x=h[i],y=h[i+1],f=0;
        for(int j=0;j<0;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res!=0) {f=1; break;}
        }
        if (f) continue;
        for (int j=1;j<2;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res==0) {
                arr[y]+=arr[x];
                arr[x]=0;
                break;
            }
        }
    }
    
    For(i,a.size()-1){
        int x=a[i],y=a[i+1],f=0;
        for(int j=0;j<1;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res!=0) {f=1; break;}
        }
        if (f) continue;
        for (int j=2;j<3;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res==0) {
                arr[y]+=arr[x];
                arr[x]=0;
                break;
            }
        }
    }
    
    For(i,r.size()-1){
        int x=r[i],y=r[i+1],f=0;
        for(int j=0;j<2;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res!=0) {f=1; break;}
        }
        if (f) continue;
        for (int j=3;j<4;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res==0) {
                arr[y]+=arr[x];
                arr[x]=0;
                break;
            }
        }
    }
    For(i,d.size()-1){
        int x=d[i],y=d[i+1],f=0;
        for(int j=0;j<3;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res!=0) {f=1; break;}
        }
        if (f) continue;
        for (int j=4;j<4;j++){
            int res=cnt[j][y];
            if (x!=0) res-=cnt[j][x-1];
            if (res==0) {
                arr[y]+=arr[x];
                arr[x]=0;
                break;
            }
        }
    }
    
    for (int j=n-1;j>-1;j-=1){
    For(i,4){
        dp[i][j]=dp[i][min(j+1,n-1)];}
    if (dd.find(s[j])==dd.end())
        continue;
    if (s[j]=='d')
        dp[3][j]+=arr[j];
    else
        dp[dd[s[j]]][j]=min(dp[dd[s[j]]][j]+arr[j],dp[dd[s[j]]+1][j]);
    
    }
    ans=dp[0][0];   
    }
    
    d1(ans);
}