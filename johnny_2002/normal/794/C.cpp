#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=3e5+10;
const int MOD=1e9+7;
const int alp=26;

int n,h[2][alp];
int ans[N];


int get(int type,int dir){
    int ans;
    if (dir==0){
        ans=0;
        while (!h[type][ans]) ans++;
        return ans;
    }
    ans=alp-1;
    while (!h[type][ans]) ans--;
    return ans;
}
void solve(){
    int pos=0;
    for(int i=alp-1,need=n-(n+1)/2;i>=0;i--)
        while (h[0][i]&&need) need--,h[0][i]--;
    for(int i=0,need=n-n/2;i<alp;i++)
        while (h[1][i]&&need) need--,h[1][i]--;
    while (pos<n){
        int c1=get(0,0),c2=get(1,1);
        if (pos%2==0){
            if (c1<c2) ans[pos++]=c1,h[0][c1]--;
            else{
                for(int i=n-1,cur=0;i>=pos;i--,cur^=1){
                    int use;
                    if (!cur) use=get(0,1);
                    else use=get(1,0);
                    ans[i]=use;
                    h[cur][use]--;
                }
                break;
            }
        }else{
            if (c2>c1) ans[pos++]=c2,h[1][c2]--;
            else {
                for(int i=n-1,cur=1;i>=pos;i--,cur^=1){
                    int use;
                    if (!cur) use=get(0,1);
                    else use=get(1,0);
                    ans[i]=use;
                    h[cur][use]--;
                }
                break;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<char(ans[i]+'a');
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    n=s1.length();
    for(auto ch:s1) h[0][ch-'a']++;
    for(auto ch:s2) h[1][ch-'a']++;
    solve();
}