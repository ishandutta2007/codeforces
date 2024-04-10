#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        int d = 0;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != s[i-1]){
                if(s[i] == 'a') d++;
                else d--;
            }
        }assert(d <= 1 && d >= -1);
        if(d){
            if(s[0] == s[1]) {
                if(s[0] == 'a') s[0]++;
                else s[0]--;
            }else s[0] = s[1];
        }
        cout<<s<<endl;
    }
    return 0;
}