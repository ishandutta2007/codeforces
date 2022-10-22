#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back

const int N=2e5+99,mx=1e7+9;

int t,n;
string s;
map<int,int> mark;

void solve(){
    int cnt=0,pos=0;
    vector<int> ans;
    cin>>s;
    n=s.size();
    mark.clear();
    f(i,0,n){
        mark[min(cnt,cnt+(s[i]=='1')-(s[i]=='0'))]++;
        cnt=cnt+(s[i]=='1')-(s[i]=='0');
    }
    ans.pb(0);
    while(mark[pos] || mark[pos-1]){
        if(1<mark[pos-1] || mark[pos]==0) pos--,mark[pos]--;
        else mark[pos]--,pos++;
        ans.pb(pos);
    }
    f(i,1,ans.size()) cout<<(ans[i-1]<ans[i] ? 1 : 0);
    cout<<endl;
}

int main(){
    cin>>t;
    while(t--)
        solve();
}