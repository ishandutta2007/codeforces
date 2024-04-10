#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=2e5+9;
int la,ra,lb,rb;
int n;
int a[M],b[M],c[M],id[M];
char s[M];
vector<pair<int,char>>ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i],id[i]=i;
    cin>>(s+1);
    sort(id+1,id+n+1,[&](const int&l,const int&r){return c[l]<c[r];});
    la=lb=1;
    if(n&1){
        for(int i=1;i<=n;i+=2){
            if(s[n]=='L')a[++ra]=i;
            else b[++rb]=i;
        }
        for(int i=2;i<=n;i+=2){
            if(s[n]=='L')b[++rb]=i;
            else a[++ra]=i;
        }
    }
    else{
        for(int i=1;i<=n;i+=2){
            if(s[n]=='L')b[++rb]=i;
            else a[++ra]=i;
        }
        for(int i=2;i<=n;i+=2){
            if(s[n]=='L')a[++ra]=i;
            else b[++rb]=i;
        }
    }
    for(int i=n-1;i>=1;--i){
        if(s[i]=='L'){
            if(s[i+1]=='L'){
                if(ra-la+1==rb-lb+1){
                    ans.eb(b[lb],'R');
                    lb++;
                }
                else{
                    ans.eb(a[la],'L');
                    la++;
                }
            }
            else {
                ans.eb(b[rb],'R');
                rb--;
            }
        }
        else{
            if(s[i+1]=='L'){
                ans.eb(a[ra],'L');
                ra--;
            }
            else {
                if(ra-la+1==rb-lb+1){
                    ans.eb(a[la],'L');
                    la++;
                }
                else{
                    ans.eb(b[lb],'R');
                    lb++;
                }
            }
        }
    }
    if(ra==la)ans.eb(a[la],'L');
    else ans.eb(b[lb],'R');
    reverse(ans.begin(),ans.end());
    for(auto o:ans){
        cout<<c[id[o.fi]]<<" "<<o.se<<endl;
    }
    return 0;
}